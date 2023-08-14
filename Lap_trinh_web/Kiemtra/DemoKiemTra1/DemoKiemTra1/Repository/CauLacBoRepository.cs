using DemoKiemTra1.Models;

namespace DemoKiemTra1.Repository
{
    public class CauLacBoRepository : ICauLacBoRepository
    {
        private readonly QlbongDaContext _context;
        
        public CauLacBoRepository(QlbongDaContext context)
        {
            _context = context;
        }

        public Caulacbo Add(Caulacbo loaiCLB)
        {
            _context.Caulacbos.Add(loaiCLB);
            _context.SaveChanges();
            return loaiCLB;
        }

        public Caulacbo Delete(string maLoaiCLB)
        {
            throw new NotImplementedException();
        }

        public IEnumerable<Caulacbo> GetCaulacbos()
        {
            return _context.Caulacbos;
        }

        public Caulacbo GetLoaiSp(string maLoaiCLB)
        {
            return _context.Caulacbos.Find(maLoaiCLB);
        }

        public Caulacbo Update(Caulacbo loaiCLB)
        {
            _context.Update(loaiCLB);
            _context.SaveChanges();
            return loaiCLB;
        }
    }
}
