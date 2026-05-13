// hitung rata rata
let nilai = [79,89,76,87,57]
let total = 0 

for (let i = 0; i < nilai.length; i++) {
    total += nilai[i]
}
let rata = total / nilai.length
console.log("rata-rata " + rata)
console.log("total "+ total)

