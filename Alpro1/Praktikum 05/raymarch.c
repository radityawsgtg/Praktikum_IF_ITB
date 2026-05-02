#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sdf.h"

typedef struct {
    Point center;
    float radius;
} Anomaly;

int main(){
    int K;
    if (scanf("%d", &K) != 1) return 0;
    Anomaly *anomalies = (Anomaly *)malloc(K * sizeof(Anomaly));
    for ( int i = 0; i < K; i++)
    {
        float cy, cx,r;
        scanf("%f %f %f", &cx, &cy, &r);
        anomalies[i].center = MakePoint(cx, cy);
        anomalies[i].radius = r;
    }
    int N;

    if (scanf("%d", &N) != 1) {
        free(anomalies);
        return 0;
    }

    for (int i = 1; i <= N; i++) {
            float px, py, vx, vy, max_dist;
            scanf("%f %f %f %f %f", &px, &py, &vx, &vy, &max_dist);

            Point start_p = MakePoint(px, py);
            Vector dir = MakeVector(vx, vy);
            
            Normalize(&dir);

            Point current_p = start_p;
            float total_dist = 0.0f;
            int steps = 0;
            float min_dist_ever = 19989799.0f; 
            int hit = 0;

            while (1) {
                float min_d = 9999999.0f;
                
                for (int j = 0; j < K; j++) {
                    float d = SDF_Circle(current_p, anomalies[j].center, anomalies[j].radius);
                    if (d < min_d) {
                        min_d = d;
                    }
                }

                if (min_d < min_dist_ever) {
                    min_dist_ever = min_d;
                }

                steps++;

                if (min_d <= 0.01f) {
                    hit = 1;
                    break;
                }

                total_dist += min_d;
                
                if (total_dist > max_dist) {
                    break;
                }

                current_p = Move(current_p, dir, min_d);
            }

            if (hit) {
                printf("Rute %d: HIT ANOMALY. Titik tembak: (%.2f, %.2f), Jumlah langkah: %d\n", i, px, py, steps);
            } else {
                printf("Rute %d: MISS. Jarak terdekat ke anomali: %.2f\n", i, min_dist_ever);
            }
        }

        free(anomalies);
        return 0;
    }