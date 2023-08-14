$(document).ready(function () {
    GetAllCustomers();
    });
    //Hàm lấy ra toàn bộ danh sách Khách Hàng. Dùng $.ajax() thực hiện method HTTP GET
    function GetAllCustomers() {
        $.ajax({
        url: 'https://localhost:44373/api/customers/',
        method: 'GET',
        contentType: 'json',
        dataType: 'json',
        success: function (reponse) {
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
            document.getElementById('allKH').innerHTML = table;
            },
    },
}