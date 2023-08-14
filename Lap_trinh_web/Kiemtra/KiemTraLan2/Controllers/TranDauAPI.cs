using KiemTraLan2.Models;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace KiemTraLan2.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class TranDauAPI : ControllerBase
    {

        QlbongDaContext db = new QlbongDaContext();
        [Route("{tranDauId}")]
        public List<Cauthu> GetAllCauThuByTranDau(string tranDauId)
        {
            /*            var lstCauthu = db.Cauthus.Where(x => x).OrderBy(x => x.HoVaTen).ToList();
                        return lstCauthu;*/
            var query = db.TrandauCauthus.Where(x => x.TranDauId == tranDauId).Select(x => x.CauThuId).ToList();
            var list = db.Cauthus.Where(x => query.Contains(x.CauThuId)).ToList();
            return list;
        }
    }
}
