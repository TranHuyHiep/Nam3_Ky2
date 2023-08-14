using DemoKiemTra1.Models;
namespace DemoKiemTra1.Repository
{
    public interface ICauLacBoRepository
    {
        Caulacbo Add(Caulacbo loaiCLB);
        Caulacbo Update(Caulacbo loaiCLB);
        Caulacbo Delete(string maLoaiCLB);
        Caulacbo GetLoaiSp(string maLoaiCLB);
        IEnumerable<Caulacbo> GetCaulacbos();
    }
}
