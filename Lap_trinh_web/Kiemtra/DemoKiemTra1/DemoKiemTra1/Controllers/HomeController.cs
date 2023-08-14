using DemoKiemTra1.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace DemoKiemTra1.Controllers
{
    public class HomeController : Controller
    {
        QlbongDaContext db = new QlbongDaContext();
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index()
        {
            var lstCauThu = db.Cauthus.ToList();
            return View(lstCauThu);
        }

        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}