using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web;
using System.Web.Http;
using System.Web.Http.Cors;

namespace DemoAPI.Controllers
{
    [EnableCors(origins: "*", headers: "*", methods: "*")]
    public class CustomerController : ApiController
    {
        //httpGet: dùng để lấy thông tin khách hàng
        //1. Dịch vụ lấy thông tin của toàn bộ khách hàng
        [HttpGet]   
        public List<tblKhach> GetCustomerLists()
        {
            DBCustomersDataContext dbCustomer = new DBCustomersDataContext();
            return dbCustomer.tblKhaches.ToList();
        }
        //2. Dịch vụ lấy thông tin một khách hàng với mã nào đó
         [HttpGet]
        public tblKhach GetCustomer(string id)
        {
            DBCustomersDataContext dbCustomer = new DBCustomersDataContext();
            return dbCustomer.tblKhaches.FirstOrDefault(x =>
           x.Makhach == id);
        }
        //3. httpPost, dịch vụ thêm mới một khách hàng
        [HttpPost]
        public bool InsertNewCustomer(string id, string name, string adress, string phoneNumber)
        {
            try
            {
                DBCustomersDataContext dbCustomer = new DBCustomersDataContext();
                tblKhach customer = new tblKhach();
                customer.Makhach = id;
                customer.TenKhach = name;
                customer.DiaChi = adress;
                customer.DienThoai = phoneNumber;

                dbCustomer.tblKhaches.InsertOnSubmit(customer);
                dbCustomer.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
        //4. httpPut để chỉnh sửa thông tin một khách hàng
        [HttpPut]
        public bool UpdateCustomer(string id, string name, string adress, string phoneNumber)
        {
            try
            {
                DBCustomersDataContext dbCustomer = new DBCustomersDataContext();
                //Lấy mã khách đã có
                tblKhach customer =
               dbCustomer.tblKhaches.FirstOrDefault(x => x.Makhach == id);
                if (customer == null) return false;
                customer.Makhach = id;
                customer.TenKhach = name;
                customer.DiaChi = adress;
                customer.DienThoai = phoneNumber;
                dbCustomer.SubmitChanges();//Xác nhận chỉnh sửa
            return true;
            }
            catch
            {
                return false;
            }
        }
        //5.httpDelete để xóa một Khách hàng
        [HttpDelete]
        public bool DeleteCustomer(string id)
        {
            try
            {
                DBCustomersDataContext dbCustomer = new DBCustomersDataContext();
                //Lấy mã khách đã có
                tblKhach customer =
               dbCustomer.tblKhaches.FirstOrDefault(x => x.Makhach == id);
                if (customer == null) return false;

                dbCustomer.tblKhaches.DeleteOnSubmit(customer);
                dbCustomer.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }

    }
}
