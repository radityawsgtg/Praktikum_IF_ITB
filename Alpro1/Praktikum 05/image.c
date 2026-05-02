#include "image.h"
bool IsPixelValid(int r, int g, int b){
    if ((r >= 0 && r<= 255)&&(g >= 0 && g<= 255)&& (b >= 0 && b<= 255))
    {
        return true;
    }
    else{
        return false;
    }
}
/* Mengirim TRUE jika nilai R, G, B berada pada rentang [0..255] (inklusif)*/

void CreatePixel(PIXEL *P, int r, int g, int b){
    if (IsPixelValid(r,g,b) == true)
    {
        Red(*P) = r;
        Green(*P)= g;
        Blue(*P) = b;

    }
    else{ 
        Red(*P)= 0;
        Green(*P)= 0;
        Blue(*P)= 0;
    }
}
/* I.S. P sembarang, r, g, b terdefinisi */
/* F.S. Jika r, g, b valid, membentuk PIXEL P.
        Jika tidak valid, P diinisialisasi dengan PIXEL hitam (0,0,0) */

void CreateImage(IMAGE *I, int r, int c){
    Rows(*I) = r;
    Cols(*I)=c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            CreatePixel(&Elmt(*I, i, j), 0, 0, 0);
        }
    }
}
/* I.S. I sembarang, r dan c terdefinisi (0 < r <= MAX_ROWS, 0 < c <= MAX_COLS)
 */
/* F.S. Membentuk IMAGE I dengan ukuran r baris dan c kolom.
        Semua elemen PIXEL di dalamnya diinisialisasi dengan warna hitam (0,0,0)
 */

void CopyImage(IMAGE I1, IMAGE *I2){
    Rows(*I2)= Rows(I1);
    Cols(*I2)= Cols(I1);
    for (int i = 0; i < Rows(I1); i++)
    {
        for (int j = 0; j < Cols(I1); j++)
        {
            Elmt(*I2,i,j) = Elmt(I1,i,j);
        }
    }
    

}
/* I.S. I1 terdefinisi, I2 sembarang */
/* F.S. I2 menjadi salinan persis (deep copy bukan hanya reference) dari I1 */

/* ***************************************************************** */
/* OPERASI DASAR PIXEL (FILTERING)                                   */
/* ***************************************************************** */
bool IsPixelEqual(PIXEL P1, PIXEL P2){
    if ((Red(P1)= Red(P2))&& (Green(P1)= Green(P2))&& (Blue(P1) = Blue(P2)))
    {
        return true;
    }
    
}
PIXEL InvertPixel(PIXEL P){
    PIXEL new;
    CreatePixel(&new,255 - Red(P),255 - Green(P),255 - Blue(P));
    return new;
}
PIXEL GrayscalePixel(PIXEL P){
    PIXEL abu;
    int abb;
    abb = ((Red(P) + Green(P) + Blue(P))/3);
    CreatePixel(&abu,abb,abb,abb);
    return abu;
}
/* Mengirim hasil konversi P menjadi warna abu-abu.
   (Rumus: R_baru = G_baru = B_baru = (R + G + B) / 3)
   Pembagian integer mengikuti aturan C (truncation toward zero). */

PIXEL AdjustBrightnessPixel(PIXEL P, int delta){
    PIXEL P_baru;
    
    int r = min(max(Red(P) + delta, 0), 255);
    int g = min(max(Green(P) + delta, 0), 255);
    int b = min(max(Blue(P) + delta, 0), 255);
    
    CreatePixel(&P_baru, r, g, b);
    return P_baru;
}
/* Mengirim PIXEL baru yang nilai R, G, B-nya ditambah dengan delta.
   Delta bisa bernilai positif (menerangkan) atau negatif (menggelapkan).
   NOTE: Nilai R, G, B harus tetap valid! */

/* ***************************************************************** */
/* OPERASI DASAR IMAGE                                               */
/* ***************************************************************** */
bool IsImageEqual(IMAGE I1, IMAGE I2){
    if (Rows(I1) != Rows(I2) || Cols(I1) != Cols(I2)) {
        return false;
    }
    
    for (int i = 0; i < Rows(I1); i++) {
        for (int j = 0; j < Cols(I1); j++) {
            if (!IsPixelEqual(Elmt(I1, i, j), Elmt(I2, i, j))) {
                return false;
            }
        }
    }
    return true;
}
/* Mengirim true jika I1 dan I2 memiliki ukuran dan isi pixel yang 100% sama */

IMAGE ApplyFilter(IMAGE I, int filterType){
    IMAGE I_baru;
    CopyImage(I, &I_baru);
    
    if (filterType == 1 || filterType == 2) {
        for (int i = 0; i < Rows(I_baru); i++) {
            for (int j = 0; j < Cols(I_baru); j++) {
                if (filterType == 1) {
                    Elmt(I_baru, i, j) = InvertPixel(Elmt(I_baru, i, j));
                } else if (filterType == 2) {
                    Elmt(I_baru, i, j) = GrayscalePixel(Elmt(I_baru, i, j));
                }
            }
        }
    }
    return I_baru;
}
/* Mengembalikan IMAGE baru hasil penerapan filter ke seluruh pixel I.
   Jika filterType == 1: Terapkan InvertPixel
   Jika filterType == 2: Terapkan GrayscalePixel
   Jika tipe lain: Kembalikan salinan I apa adanya. */

IMAGE CropImage(IMAGE I, int startRow, int startCol, int endRow, int endCol){
    IMAGE I_baru;
    int new_r = endRow - startRow + 1;
    int new_c = endCol - startCol + 1;
    
    CreateImage(&I_baru, new_r, new_c);
    
    for (int i = 0; i < new_r; i++) {
        for (int j = 0; j < new_c; j++) {
            Elmt(I_baru, i, j) = Elmt(I, startRow + i, startCol + j);
        }
    }
    return I_baru;
}
/* Mengembalikan IMAGE baru berupa potongan (sub-image) dari I.
   Prekondisi: startRow <= endRow, startCol <= endCol, dan koordinat valid.
   Ukuran IMAGE baru adalah (endRow - startRow + 1) x (endCol - startCol + 1).
*/

IMAGE BlendImage(IMAGE I1, IMAGE I2){
    IMAGE I_baru;
    CreateImage(&I_baru, Rows(I1), Cols(I1));
    
    for (int i = 0; i < Rows(I1); i++) {
        for (int j = 0; j < Cols(I1); j++) {
            int r_baru = (Red(Elmt(I1, i, j)) + Red(Elmt(I2, i, j))) / 2;
            int g_baru = (Green(Elmt(I1, i, j)) + Green(Elmt(I2, i, j))) / 2;
            int b_baru = (Blue(Elmt(I1, i, j)) + Blue(Elmt(I2, i, j))) / 2;
            CreatePixel(&Elmt(I_baru, i, j), r_baru, g_baru, b_baru);
        }
    }
    return I_baru;
}
/* Mengembalikan IMAGE baru hasil percampuran (overlay) I1 dan I2.
   Prekondisi: Ukuran I1 dan I2 dijamin sama.
   Rumus pixel baru: R_baru = (R_I1 + R_I2) / 2 (Lakukan pada G dan B juga).
*/