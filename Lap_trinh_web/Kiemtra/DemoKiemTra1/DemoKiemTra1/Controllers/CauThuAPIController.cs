using DemoKiemTra1.Models;
using Microsoft.AspNetCore.Mvc;
using DemoKiemTra1.Models.CauThuModels;

namespace DemoKiemTra1.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class CauThuAPIController : ControllerBase
    {
        QlbongDaContext db = new QlbongDaContext();
        [HttpGet]
        public IEnumerable<CauThu> GetAllCauThus()
        {
            var cauThus = (from p in db.Cauthus
                            select new CauThu
                            {
                                CauThuId = p.CauThuId,
                                HoVaTen = p.HoVaTen,
                                SoAo = p.SoAo,
                                QuocTich = p.QuocTich,
                                CauLacBoId = p.CauLacBoId
                            }).ToList();
            return cauThus;
        }

        [HttpGet("{maCLB}")]
        public IEnumerable<CauThu> GetProductsByCLB(string maCLB)
        {
            var cauThus = (from p in db.Cauthus
                            where p.CauLacBoId == maCLB
                           select new CauThu
                           {
                               CauThuId = p.CauThuId,
                               HoVaTen = p.HoVaTen,
                               SoAo = p.SoAo,
                               QuocTich = p.QuocTich,
                               CauLacBoId = p.CauLacBoId
                           }).ToList();
            return cauThus;
        }
    }
}
