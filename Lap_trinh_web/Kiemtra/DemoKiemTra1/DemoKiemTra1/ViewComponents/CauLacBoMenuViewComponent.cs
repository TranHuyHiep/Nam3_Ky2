using DemoKiemTra1.Repository;
using Microsoft.AspNetCore.Mvc;

namespace DemoKiemTra1.ViewComponents
{
    public class CauLacBoMenuViewComponent : ViewComponent
    {
        private readonly ICauLacBoRepository _loaiCLB;
        public CauLacBoMenuViewComponent(ICauLacBoRepository cauLacBoRepository)
        {
            _loaiCLB = cauLacBoRepository;
        }

        public IViewComponentResult Invoke()
        {
            var loaiCLB = _loaiCLB.GetCaulacbos().OrderBy(x => x.TenClb);
            return View(loaiCLB);
        }
    }
}
