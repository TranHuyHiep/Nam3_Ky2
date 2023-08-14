$(document).ready(function () {
    GetAllCustomers();
});
function GetAllCustomers() {
    $.ajax({
        url: 'https://localhost:44357/api/customer',
        method: 'GET',
        contentType: 'json',
        dataType: 'json',
        error: function (response) {
        }, success: function (reponse) {
            const len = reponse.length;
            console.log(reponse);
            let table = '';
            for (var i = 0; i < len; ++i) {
                table = table + '<tr>';
                table = table + '<td>' + reponse[i].MaKH + '</td>';
                table = table + '<td>' + reponse[i].TenKH + '</td>';
                table = table + '<td>' + reponse[i].DiaChi + '</td>';
                table = table + '<td>' + reponse[i].DienThoai + '</td>';
                table = table + '</tr>';
            }
            document.getElementById('display').innerHTML = table;
        },
        fail: function (response) {
        }
    });
}