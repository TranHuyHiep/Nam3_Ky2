using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Http;
using System.Web.Http.Cors;

namespace DemoAPI.Controllers
{
    [EnableCors(origins: "*", headers: "*", methods: "*")]
    public class ProductController : ApiController
    {
        [HttpGet]
        public List<tblHang> GetHangLists()
        {
            DBHangsDataContext db = new DBHangsDataContext();
            return db.tblHangs.ToList();
        }

        [HttpGet]
        public tblHang GetHang(string id)
        {
            DBHangsDataContext db = new DBHangsDataContext();
            return db.tblHangs.FirstOrDefault(x => x.Mahang == id);
        }
    }
}