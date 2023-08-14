using System;
using System.Collections.Generic;

namespace DemoKiemTra1.Models;

public partial class Caulacbo
{
    public string CauLacBoId { get; set; } = null!;

    public string? TenClb { get; set; }

    public string? TenGoi { get; set; }

    public string? SanVanDongId { get; set; }

    public string? HuanLuyenVienId { get; set; }

    public int? SoCauThu { get; set; }

    public virtual ICollection<Cauthu> Cauthus { get; } = new List<Cauthu>();

    public virtual ICollection<TrandauGhiban> TrandauGhibans { get; } = new List<TrandauGhiban>();
}
