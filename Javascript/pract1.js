const mahasiswa = [{nama:"Raditya",Nilai:88,Jurusan:"Teknik Informatika"},{nama:"Sar",Nilai:88,Jurusan:"STI"},{nama:"Shaqnat",Nilai:80,Jurusan:"Tekfor"},{nama:"claud",Nilai:87,Jurusan:"AIMEL"},{nama:"Geminuy",Nilai:65,Jurusan:"AIMEL"}]
console.log(mahasiswa.length)

let lulus = mahasiswa.filter(p => p.Nilai > 70)
lulus.forEach(p => console.log(p.nama + " Lulus dengan nilai " + p.Nilai))

function hitungRata(arr){
    const total = arr.reduce((acc,m)=> acc + m.Nilai,0)
    return total / arr.length
}

console.log(hitungRata(mahasiswa).toFixed(2))
