using KiemTraLan2.Models;
using Microsoft.AspNetCore.Mvc;

namespace KiemTraLan2.ViewComponents
{
    public class CauLacBoMenuViewComponent : ViewComponent
    {
        QlbongDaContext db = new QlbongDaContext();
        public CauLacBoMenuViewComponent() { }

        public IViewComponentResult Invoke()
        {
            var lstCLB = db.Trandaus.Take(7).ToList();
            return View(lstCLB);
        }
    }
}
