using KiemTraLan2.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using System.Diagnostics;

namespace KiemTraLan2.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        QlbongDaContext db = new QlbongDaContext();
        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index()
        {
            var lstCauThu = db.Cauthus.Where(x => x.CauLacBoId == "101").OrderBy(x => x.HoVaTen).ToList();
            return View(lstCauThu);
        }

        // them
        [HttpGet]
        public IActionResult ThemCauThu()
        {
            ViewBag.CauLacBoId = new SelectList(db.Caulacbos.ToList(), "CauLacBoId", "TenClb");
            return View();
        }

        [HttpPost]
        public IActionResult ThemCauThu(Cauthu cauthu)
        {
            if (ModelState.IsValid)
            {
                db.Cauthus.Add(cauthu);
                db.SaveChanges();
                return RedirectToAction("Index", "Home");
            }
            ViewBag.CauLacBoId = new SelectList(db.Caulacbos.ToList(), "CauLacBoId", "TenClb");
            return View(cauthu);
        }


// chi tiet
[HttpGet]
public IActionResult ChiTietCauThu(string cauThuId)
{
    var temp = db.Cauthus.SingleOrDefault(x => x.CauThuId == cauThuId);
    return View(temp);
}

        // sua 
        [HttpGet]
        public IActionResult suaCauThu(string cauThuId)
        {
            var temp = db.Cauthus.SingleOrDefault(x => x.CauThuId == cauThuId);
            ViewBag.CauLacBoId = new SelectList(db.Caulacbos.ToList(), "CauLacBoId", "TenClb");
            return View(temp);
        }

        [HttpPost]
        public IActionResult suaCauThu(Cauthu cauthu)
        {
            if (ModelState.IsValid)
            {
                db.Cauthus.Update(cauthu);
                db.SaveChanges();
                return RedirectToAction("Index", "Home");
            }
            ViewBag.CauLacBoId = new SelectList(db.Caulacbos.ToList(), "CauLacBoId", "TenClb");
            return View(cauthu);
        }
    }
}