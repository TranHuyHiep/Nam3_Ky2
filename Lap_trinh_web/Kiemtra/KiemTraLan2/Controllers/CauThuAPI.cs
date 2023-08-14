using KiemTraLan2.Models;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace KiemTraLan2.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class CauThuAPI : ControllerBase
    {
        QlbongDaContext db = new QlbongDaContext();
        [Route("{maclb}")]
        public List<Cauthu> GetAllCauThuByCLB(string maclb)
        {
            var lstCauthu = db.Cauthus.Where(x => x.CauLacBoId == maclb).OrderBy(x => x.HoVaTen).ToList();
            return lstCauthu;
        }
    }
}
