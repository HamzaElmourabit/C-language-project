document.getElementById('employeForm').addEventListener('submit', function(e) {
    e.preventDefault();
    const nom = document.getElementById('nom').value;
    const heures = parseFloat(document.getElementById('heures').value);
    const taux = parseFloat(document.getElementById('taux').value);

    const salaireBrut = heures * taux;
    const deductions = salaireBrut * 0.10;
    const salaireNet = salaireBrut - deductions;

    const table = document.getElementById('employesTable').getElementsByTagName('tbody')[0];
    const row = table.insertRow();
    row.insertCell(0).innerText = nom;
    row.insertCell(1).innerText = heures;
    row.insertCell(2).innerText = taux;
    row.insertCell(3).innerText = salaireBrut.toFixed(2);
    row.insertCell(4).innerText = deductions.toFixed(2);
    row.insertCell(5).innerText = salaireNet.toFixed(2);

    document.getElementById('employeForm').reset();
});