USE [QuanLyBanGiay]
GO
/****** Object:  Table [dbo].[tChiTietGioHang]    Script Date: 19/05/2020 10:07:06 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tChiTietGioHang](
	[MaGioHang] [int] NOT NULL,
	[MaSP] [nchar](10) NOT NULL,
	[MaSize] [nvarchar](50) NOT NULL,
	[Gia] [bigint] NULL,
	[SoLuong] [int] NULL,
 CONSTRAINT [PK_tChiTietGioHang] PRIMARY KEY CLUSTERED 
(
	[MaGioHang] ASC,
	[MaSP] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tChiTietHoaDon]    Script Date: 19/05/2020 10:07:06 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tChiTietHoaDon](
	[MaHD] [int] NOT NULL,
	[MaSP] [nchar](10) NOT NULL,
	[GhiChu] [nchar](50) NULL,
	[SoLuong] [int] NULL,
 CONSTRAINT [PK_tChiTietHD] PRIMARY KEY CLUSTERED 
(
	[MaHD] ASC,
	[MaSP] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tGioHang]    Script Date: 19/05/2020 10:07:06 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tGioHang](
	[MaGioHang] [int] NOT NULL,
	[TenTK] [nvarchar](50) NULL,
 CONSTRAINT [PK_tGioHang] PRIMARY KEY CLUSTERED 
(
	[MaGioHang] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tHoaDon]    Script Date: 19/05/2020 10:07:06 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tHoaDon](
	[MaHD] [int] IDENTITY(1,1) NOT NULL,
	[TenTK] [nvarchar](50) NOT NULL,
	[NgayDat] [date] NULL,
 CONSTRAINT [PK_tHoaDon] PRIMARY KEY CLUSTERED 
(
	[MaHD] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tSanPham]    Script Date: 19/05/2020 10:07:06 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tSanPham](
	[MaSP] [nchar](10) NOT NULL,
	[TenSP] [nvarchar](50) NULL,
	[Gia] [int] NULL,
	[GioiTinh] [nvarchar](50) NOT NULL,
	[TheLoai] [nvarchar](50) NOT NULL,
	[Anh] [nvarchar](50) NULL,
	[sale] [int] NULL,
 CONSTRAINT [PK_tSanPham] PRIMARY KEY CLUSTERED 
(
	[MaSP] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tTaiKhoan]    Script Date: 19/05/2020 10:07:06 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tTaiKhoan](
	[TenTK] [nvarchar](50) NOT NULL,
	[Password] [nvarchar](50) NULL,
	[TenKH] [nvarchar](50) NULL,
	[NgaySinh] [date] NULL,
	[Email] [nvarchar](50) NULL,
 CONSTRAINT [PK_tTaiKhoan] PRIMARY KEY CLUSTERED 
(
	[TenTK] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[tSanPham] ([MaSP], [TenSP], [Gia], [GioiTinh], [TheLoai], [Anh], [sale]) VALUES (N'1         ', N'1', 1, N'1', N'1', N'1', 2)
INSERT [dbo].[tSanPham] ([MaSP], [TenSP], [Gia], [GioiTinh], [TheLoai], [Anh], [sale]) VALUES (N'G001      ', N'Bitis01', 650000, N'Nam', N'The Thao', N'na1.jpg', 1)
INSERT [dbo].[tSanPham] ([MaSP], [TenSP], [Gia], [GioiTinh], [TheLoai], [Anh], [sale]) VALUES (N'G002      ', N'Bitis02', 650000, N'Nam', N'The Thao', N'DSW053233DEN_main_800.jpg', 1)
INSERT [dbo].[tSanPham] ([MaSP], [TenSP], [Gia], [GioiTinh], [TheLoai], [Anh], [sale]) VALUES (N'G003      ', N'Bitis03', 650000, N'Nu', N'The Thao', N'tải xuống.jpg', 1)
INSERT [dbo].[tSanPham] ([MaSP], [TenSP], [Gia], [GioiTinh], [TheLoai], [Anh], [sale]) VALUES (N'G004      ', N'Bitis04', 650000, N'Nu', N'The Thao', N'DSM062633DOO_main_400.jpg', 1)
INSERT [dbo].[tSanPham] ([MaSP], [TenSP], [Gia], [GioiTinh], [TheLoai], [Anh], [sale]) VALUES (N'G005      ', N'Bitis05', 550000, N'Nu', N'The Thao', N'DSM065233DEN_main_800.jpg', 0)
INSERT [dbo].[tSanPham] ([MaSP], [TenSP], [Gia], [GioiTinh], [TheLoai], [Anh], [sale]) VALUES (N'G006      ', N'Bitis06', 560000, N'Nam', N'The Thao', N'DSM063833XDD_main_800.jpg', 0)
INSERT [dbo].[tSanPham] ([MaSP], [TenSP], [Gia], [GioiTinh], [TheLoai], [Anh], [sale]) VALUES (N'G007      ', N'Bitis07', 500000, N'Nu', N'The Thao', N'DSW053133XNH_main_800.jpg', 0)
INSERT [dbo].[tSanPham] ([MaSP], [TenSP], [Gia], [GioiTinh], [TheLoai], [Anh], [sale]) VALUES (N'G008      ', N'Bitis08', 450000, N'Nu', N'The Thao', N'DSM063233DEN_main_800.jpg', 0)
ALTER TABLE [dbo].[tChiTietGioHang]  WITH CHECK ADD  CONSTRAINT [FK_tChiTietGioHang_tGioHang] FOREIGN KEY([MaGioHang])
REFERENCES [dbo].[tGioHang] ([MaGioHang])
GO
ALTER TABLE [dbo].[tChiTietGioHang] CHECK CONSTRAINT [FK_tChiTietGioHang_tGioHang]
GO
ALTER TABLE [dbo].[tChiTietGioHang]  WITH CHECK ADD  CONSTRAINT [FK_tChiTietGioHang_tSanPham] FOREIGN KEY([MaSP])
REFERENCES [dbo].[tSanPham] ([MaSP])
GO
ALTER TABLE [dbo].[tChiTietGioHang] CHECK CONSTRAINT [FK_tChiTietGioHang_tSanPham]
GO
ALTER TABLE [dbo].[tChiTietHoaDon]  WITH CHECK ADD  CONSTRAINT [FK_tChiTietHD_tHoaDon] FOREIGN KEY([MaHD])
REFERENCES [dbo].[tHoaDon] ([MaHD])
GO
ALTER TABLE [dbo].[tChiTietHoaDon] CHECK CONSTRAINT [FK_tChiTietHD_tHoaDon]
GO
ALTER TABLE [dbo].[tChiTietHoaDon]  WITH CHECK ADD  CONSTRAINT [FK_tChiTietHD_tSanPham] FOREIGN KEY([MaSP])
REFERENCES [dbo].[tSanPham] ([MaSP])
GO
ALTER TABLE [dbo].[tChiTietHoaDon] CHECK CONSTRAINT [FK_tChiTietHD_tSanPham]
GO
ALTER TABLE [dbo].[tHoaDon]  WITH CHECK ADD  CONSTRAINT [FK_tHoaDon_tTaiKhoan] FOREIGN KEY([TenTK])
REFERENCES [dbo].[tTaiKhoan] ([TenTK])
GO
ALTER TABLE [dbo].[tHoaDon] CHECK CONSTRAINT [FK_tHoaDon_tTaiKhoan]
GO
