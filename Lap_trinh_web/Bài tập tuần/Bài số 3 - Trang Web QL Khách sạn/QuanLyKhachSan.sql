USE [QuanLyKhachSan]
GO
/****** Object:  Table [dbo].[tChiTietDatPhong]    Script Date: 28/04/2020 9:04:45 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tChiTietDatPhong](
	[MaDP] [char](15) NOT NULL,
	[LoaiPhong] [char](15) NOT NULL,
	[SLPhongDat] [tinyint] NOT NULL,
 CONSTRAINT [pk_tChiTietDatPhong] PRIMARY KEY CLUSTERED 
(
	[MaDP] ASC,
	[LoaiPhong] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tChiTietKH]    Script Date: 28/04/2020 9:04:45 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tChiTietKH](
	[MaKH] [char](15) NOT NULL,
	[LoaiKH] [char](15) NULL,
	[TenKH] [nvarchar](50) NULL,
	[NgaySinh] [datetime] NULL,
	[Phai] [bit] NOT NULL,
	[DiaChi] [nvarchar](50) NULL,
	[DienThoai] [nvarchar](7) NULL,
	[DiemTichLuy] [int] NULL,
	[TheCanCuoc] [nvarchar](20) NULL,
 CONSTRAINT [pk_tChiTietKH] PRIMARY KEY CLUSTERED 
(
	[MaKH] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tDangKy]    Script Date: 28/04/2020 9:04:46 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tDangKy](
	[MaDK] [char](15) NOT NULL,
	[MaKH] [char](15) NULL,
	[SoPhong] [char](15) NULL,
	[NgayVao] [datetime] NULL,
	[NgayRa] [datetime] NULL,
 CONSTRAINT [pk_tDangKy] PRIMARY KEY CLUSTERED 
(
	[MaDK] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tDanhGia]    Script Date: 28/04/2020 9:04:46 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tDanhGia](
	[MaDG] [char](15) NOT NULL,
	[NoiDung] [nvarchar](4000) NULL,
	[NguoiDanhGia] [nvarchar](50) NULL,
	[email] [nvarchar](50) NULL,
	[DiaChi] [nvarchar](50) NULL,
	[ViTri] [nchar](1) NULL,
	[PhucVu] [nchar](1) NULL,
	[TienNghi] [nchar](1) NULL,
	[GiaCa] [nchar](1) NULL,
	[VeSinh] [nchar](1) NULL,
	[MonAn] [nchar](1) NULL,
 CONSTRAINT [pk_tDanhGiay] PRIMARY KEY CLUSTERED 
(
	[MaDG] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tDatPhong]    Script Date: 28/04/2020 9:04:46 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tDatPhong](
	[MaDP] [char](15) NOT NULL,
	[MaKH] [char](15) NULL,
	[Diachi] [nvarchar](250) NULL,
	[TenCongTy] [nvarchar](250) NULL,
	[MaSoThue] [nvarchar](150) NULL,
	[DiaChiCty] [nvarchar](255) NULL,
 CONSTRAINT [pk_tDatPhongy] PRIMARY KEY CLUSTERED 
(
	[MaDP] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tDoanhThu]    Script Date: 28/04/2020 9:04:46 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tDoanhThu](
	[MaDK] [char](15) NOT NULL,
	[LoaiPhong] [char](15) NULL,
	[SoNgayO] [int] NULL,
	[ThucThu] [float] NULL,
 CONSTRAINT [PK_tDoanhThu] PRIMARY KEY CLUSTERED 
(
	[MaDK] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tLoaiKhachHang]    Script Date: 28/04/2020 9:04:46 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tLoaiKhachHang](
	[LoaiKH] [char](15) NOT NULL,
	[DienGiai] [nvarchar](50) NULL,
 CONSTRAINT [PK_tLoaiKhachHang] PRIMARY KEY CLUSTERED 
(
	[LoaiKH] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tLoaiPhong]    Script Date: 28/04/2020 9:04:46 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tLoaiPhong](
	[LoaiPhong] [char](15) NOT NULL,
	[MoTa] [nvarchar](50) NULL,
	[DonGia] [int] NULL,
	[HinhAnh] [nvarchar](50) NULL,
	[DienTich] [nchar](10) NULL,
	[SoGiuong] [nchar](1) NULL,
	[SoPhongNgu] [nchar](1) NULL,
	[BonTam] [nchar](1) NULL,
	[SoPhongTam] [nchar](1) NULL,
	[Gia] [float] NULL,
 CONSTRAINT [PK_tLoaiPhong] PRIMARY KEY CLUSTERED 
(
	[LoaiPhong] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tSoPhong_LoaiPhong]    Script Date: 28/04/2020 9:04:46 SA ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tSoPhong_LoaiPhong](
	[SoPhong] [char](15) NOT NULL,
	[LoaiPhong] [char](15) NOT NULL,
 CONSTRAINT [PK_tSoPhong_LoaiPhong_1] PRIMARY KEY CLUSTERED 
(
	[SoPhong] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[tChiTietKH] ([MaKH], [LoaiKH], [TenKH], [NgaySinh], [Phai], [DiaChi], [DienThoai], [DiemTichLuy], [TheCanCuoc]) VALUES (N'001            ', N'1              ', N'Trần Hồng Hà', CAST(N'1980-12-12T00:00:00.000' AS DateTime), 0, N'34A Trần phú', NULL, NULL, NULL)
INSERT [dbo].[tChiTietKH] ([MaKH], [LoaiKH], [TenKH], [NgaySinh], [Phai], [DiaChi], [DienThoai], [DiemTichLuy], [TheCanCuoc]) VALUES (N'002            ', N'1              ', N'Nguyễn Thế Anh', CAST(N'1968-03-22T00:00:00.000' AS DateTime), 0, N'123 Trần Hưng Đạo', NULL, NULL, NULL)
INSERT [dbo].[tChiTietKH] ([MaKH], [LoaiKH], [TenKH], [NgaySinh], [Phai], [DiaChi], [DienThoai], [DiemTichLuy], [TheCanCuoc]) VALUES (N'003            ', N'1              ', N'Lê Gia Linh', CAST(N'1981-04-12T00:00:00.000' AS DateTime), 1, N'564 Nguyễn Trãi', N'8445563', NULL, NULL)
INSERT [dbo].[tChiTietKH] ([MaKH], [LoaiKH], [TenKH], [NgaySinh], [Phai], [DiaChi], [DienThoai], [DiemTichLuy], [TheCanCuoc]) VALUES (N'004            ', N'3              ', N'Nguyễn Thị Minh tâm', CAST(N'1975-05-23T00:00:00.000' AS DateTime), 1, N'56/12 Đặng văn Ngữ', NULL, NULL, NULL)
INSERT [dbo].[tChiTietKH] ([MaKH], [LoaiKH], [TenKH], [NgaySinh], [Phai], [DiaChi], [DienThoai], [DiemTichLuy], [TheCanCuoc]) VALUES (N'005            ', N'1              ', N'Nguyễn Kim Sơn', CAST(N'1969-09-12T00:00:00.000' AS DateTime), 0, N'78/9 Nguyễn Thị Minh Khai', N'8355647', NULL, NULL)
INSERT [dbo].[tChiTietKH] ([MaKH], [LoaiKH], [TenKH], [NgaySinh], [Phai], [DiaChi], [DienThoai], [DiemTichLuy], [TheCanCuoc]) VALUES (N'006            ', N'1              ', N'Trần Hạnh Dung', CAST(N'1952-12-15T00:00:00.000' AS DateTime), 1, N'34 Lê Duẩn', NULL, NULL, NULL)
INSERT [dbo].[tChiTietKH] ([MaKH], [LoaiKH], [TenKH], [NgaySinh], [Phai], [DiaChi], [DienThoai], [DiemTichLuy], [TheCanCuoc]) VALUES (N'007            ', N'2              ', N'Lý Mỹ Lệ', CAST(N'1980-01-16T00:00:00.000' AS DateTime), 1, N'14/2 Vũ Trọng Phụng', N'8679456', NULL, NULL)
INSERT [dbo].[tChiTietKH] ([MaKH], [LoaiKH], [TenKH], [NgaySinh], [Phai], [DiaChi], [DienThoai], [DiemTichLuy], [TheCanCuoc]) VALUES (N'008            ', N'2              ', N'Nguyễn Kim An', CAST(N'1963-03-12T00:00:00.000' AS DateTime), 0, N'23 Trần Bình Trọng', NULL, 40000, NULL)
INSERT [dbo].[tChiTietKH] ([MaKH], [LoaiKH], [TenKH], [NgaySinh], [Phai], [DiaChi], [DienThoai], [DiemTichLuy], [TheCanCuoc]) VALUES (N'009            ', N'1              ', N'Nguyễn Phương Dung', CAST(N'1982-06-10T00:00:00.000' AS DateTime), 1, N'67 Hoàng Hoa Thám', N'8767752', NULL, NULL)
INSERT [dbo].[tChiTietKH] ([MaKH], [LoaiKH], [TenKH], [NgaySinh], [Phai], [DiaChi], [DienThoai], [DiemTichLuy], [TheCanCuoc]) VALUES (N'010            ', N'1              ', N'Lê Thị Kim thảo', CAST(N'1969-09-03T00:00:00.000' AS DateTime), 1, N'56 Nguyễn Tuân', NULL, NULL, NULL)
INSERT [dbo].[tDangKy] ([MaDK], [MaKH], [SoPhong], [NgayVao], [NgayRa]) VALUES (N'001            ', NULL, N'201            ', CAST(N'1998-04-15T00:00:00.000' AS DateTime), CAST(N'1998-04-28T00:00:00.000' AS DateTime))
INSERT [dbo].[tDangKy] ([MaDK], [MaKH], [SoPhong], [NgayVao], [NgayRa]) VALUES (N'002            ', NULL, N'202            ', CAST(N'1998-04-30T00:00:00.000' AS DateTime), CAST(N'1998-05-03T00:00:00.000' AS DateTime))
INSERT [dbo].[tDangKy] ([MaDK], [MaKH], [SoPhong], [NgayVao], [NgayRa]) VALUES (N'003            ', NULL, N'101            ', CAST(N'1998-05-20T00:00:00.000' AS DateTime), CAST(N'1998-06-01T00:00:00.000' AS DateTime))
INSERT [dbo].[tDangKy] ([MaDK], [MaKH], [SoPhong], [NgayVao], [NgayRa]) VALUES (N'004            ', NULL, N'102            ', CAST(N'1998-05-02T00:00:00.000' AS DateTime), CAST(N'1998-05-15T00:00:00.000' AS DateTime))
INSERT [dbo].[tDangKy] ([MaDK], [MaKH], [SoPhong], [NgayVao], [NgayRa]) VALUES (N'005            ', NULL, N'405            ', CAST(N'1998-05-03T00:00:00.000' AS DateTime), CAST(N'1998-05-05T00:00:00.000' AS DateTime))
INSERT [dbo].[tDangKy] ([MaDK], [MaKH], [SoPhong], [NgayVao], [NgayRa]) VALUES (N'006            ', NULL, N'608            ', CAST(N'1998-06-05T00:00:00.000' AS DateTime), CAST(N'1998-07-05T00:00:00.000' AS DateTime))
INSERT [dbo].[tDangKy] ([MaDK], [MaKH], [SoPhong], [NgayVao], [NgayRa]) VALUES (N'007            ', NULL, N'304            ', CAST(N'1998-06-05T00:00:00.000' AS DateTime), CAST(N'1998-06-08T00:00:00.000' AS DateTime))
INSERT [dbo].[tDangKy] ([MaDK], [MaKH], [SoPhong], [NgayVao], [NgayRa]) VALUES (N'008            ', NULL, N'201            ', CAST(N'1998-06-30T00:00:00.000' AS DateTime), CAST(N'1998-07-15T00:00:00.000' AS DateTime))
INSERT [dbo].[tDangKy] ([MaDK], [MaKH], [SoPhong], [NgayVao], [NgayRa]) VALUES (N'009            ', NULL, N'205            ', CAST(N'1999-07-01T00:00:00.000' AS DateTime), CAST(N'1999-07-30T00:00:00.000' AS DateTime))
INSERT [dbo].[tDangKy] ([MaDK], [MaKH], [SoPhong], [NgayVao], [NgayRa]) VALUES (N'010            ', NULL, N'601            ', CAST(N'1999-01-01T00:00:00.000' AS DateTime), CAST(N'1999-01-12T00:00:00.000' AS DateTime))
INSERT [dbo].[tDanhGia] ([MaDG], [NoiDung], [NguoiDanhGia], [email], [DiaChi], [ViTri], [PhucVu], [TienNghi], [GiaCa], [VeSinh], [MonAn]) VALUES (N'00001          ', N'Tôi thấy dịch vụ cơ bản cũng ở mức bình thường, không có gì nổi bật nhưng cũng không có gì phàn nàn. Vị trí đi lại thuận tiện, tôi đánh giá tốt vị trí của khách sạn. Nhân viên cũng ok, vệ sinh ổn, tôi thấy giá như vậy là hơi cao', N'Nguyễn Trường An', N'ngtan@gmail.com', N'Hà Nội', N'8', N'7', N'7', N'6', N'7', N'7')
INSERT [dbo].[tDanhGia] ([MaDG], [NoiDung], [NguoiDanhGia], [email], [DiaChi], [ViTri], [PhucVu], [TienNghi], [GiaCa], [VeSinh], [MonAn]) VALUES (N'00002          ', N'Khách sạn xứng đáng với tiêu chuẩn 5 sao, không gian khách sạn rất sang trọng và đẹp. Chương trình giải trí, ăn uống cũng như các tiện ích trong phòng đầy đủ cả. Nhân viên làm việc nhanh nhẹn, có hệ thống. Căn phòng của tôi ở tốt, view cũng tuyệt. Xét về giá thì dịch vụ tương xứng', N'Trần Công Tâm', N'trctam@gmail.com', N'Thái Nguyên', N'7', N'8', N'8', N'8', N'5', N'5')
INSERT [dbo].[tDanhGia] ([MaDG], [NoiDung], [NguoiDanhGia], [email], [DiaChi], [ViTri], [PhucVu], [TienNghi], [GiaCa], [VeSinh], [MonAn]) VALUES (N'00003          ', N'Theo cảm nhận khách quan của riêng cá nhân tôi thì về cơ sở vật chất, nội thất được nhưng về cung cách phục vụ của nhân viên thì không tốt, họ không nhiệt tình, nhiều khi họ còn tỏ thái độ gắt gỏng với trẻ con. Khách sạn 5 sao gì mà không tự động dọn phòng mỗi ngày, đợi khách nhắc thì mới nhớ dọn phòng cho khách', N'Nguyễn Thị Như Lan', N'ngtnhulan@gmail.com', N'Hải Phòng', N'7', N'6', N'6', N'6', N'6', N'6')
INSERT [dbo].[tDoanhThu] ([MaDK], [LoaiPhong], [SoNgayO], [ThucThu]) VALUES (N'006            ', N'C              ', 30, 2700000)
INSERT [dbo].[tDoanhThu] ([MaDK], [LoaiPhong], [SoNgayO], [ThucThu]) VALUES (N'007            ', N'C              ', 12, 3000000)
INSERT [dbo].[tDoanhThu] ([MaDK], [LoaiPhong], [SoNgayO], [ThucThu]) VALUES (N'008            ', N'A              ', 23, 4000000)
INSERT [dbo].[tLoaiKhachHang] ([LoaiKH], [DienGiai]) VALUES (N'1              ', N'Khách vãng lai')
INSERT [dbo].[tLoaiKhachHang] ([LoaiKH], [DienGiai]) VALUES (N'2              ', N'Khách hàng thân thiết')
INSERT [dbo].[tLoaiKhachHang] ([LoaiKH], [DienGiai]) VALUES (N'3              ', N'Khách có thẻ của công ty Bảo hiểm')
INSERT [dbo].[tLoaiPhong] ([LoaiPhong], [MoTa], [DonGia], [HinhAnh], [DienTich], [SoGiuong], [SoPhongNgu], [BonTam], [SoPhongTam], [Gia]) VALUES (N'A              ', N'Phòng đôi, một giường đôi, không gian rộng', 2000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[tLoaiPhong] ([LoaiPhong], [MoTa], [DonGia], [HinhAnh], [DienTich], [SoGiuong], [SoPhongNgu], [BonTam], [SoPhongTam], [Gia]) VALUES (N'B              ', N'Phòng đôi, vmột giường đôi, không gian hẹp', 1500000, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[tLoaiPhong] ([LoaiPhong], [MoTa], [DonGia], [HinhAnh], [DienTich], [SoGiuong], [SoPhongNgu], [BonTam], [SoPhongTam], [Gia]) VALUES (N'C              ', N'Phòng đơn, không gian rộng', 1000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[tLoaiPhong] ([LoaiPhong], [MoTa], [DonGia], [HinhAnh], [DienTich], [SoGiuong], [SoPhongNgu], [BonTam], [SoPhongTam], [Gia]) VALUES (N'D              ', N'Phòng đơn, không gian hẹp', 900000, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[tLoaiPhong] ([LoaiPhong], [MoTa], [DonGia], [HinhAnh], [DienTich], [SoGiuong], [SoPhongNgu], [BonTam], [SoPhongTam], [Gia]) VALUES (N'E              ', N'Phòng đôi, hai giường nhỏ, không gian rộng', 2200000, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[tLoaiPhong] ([LoaiPhong], [MoTa], [DonGia], [HinhAnh], [DienTich], [SoGiuong], [SoPhongNgu], [BonTam], [SoPhongTam], [Gia]) VALUES (N'F              ', N'Phòng đôi, hai giường nhỏ, không gian hẹp', 1700000, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
INSERT [dbo].[tSoPhong_LoaiPhong] ([SoPhong], [LoaiPhong]) VALUES (N'101            ', N'A              ')
INSERT [dbo].[tSoPhong_LoaiPhong] ([SoPhong], [LoaiPhong]) VALUES (N'102            ', N'A              ')
INSERT [dbo].[tSoPhong_LoaiPhong] ([SoPhong], [LoaiPhong]) VALUES (N'201            ', N'A              ')
INSERT [dbo].[tSoPhong_LoaiPhong] ([SoPhong], [LoaiPhong]) VALUES (N'202            ', N'B              ')
INSERT [dbo].[tSoPhong_LoaiPhong] ([SoPhong], [LoaiPhong]) VALUES (N'205            ', N'A              ')
INSERT [dbo].[tSoPhong_LoaiPhong] ([SoPhong], [LoaiPhong]) VALUES (N'304            ', N'C              ')
INSERT [dbo].[tSoPhong_LoaiPhong] ([SoPhong], [LoaiPhong]) VALUES (N'405            ', N'B              ')
INSERT [dbo].[tSoPhong_LoaiPhong] ([SoPhong], [LoaiPhong]) VALUES (N'601            ', N'B              ')
INSERT [dbo].[tSoPhong_LoaiPhong] ([SoPhong], [LoaiPhong]) VALUES (N'608            ', N'C              ')
ALTER TABLE [dbo].[tChiTietDatPhong]  WITH CHECK ADD  CONSTRAINT [FK_tChiTietDatPhong_tDatPhong] FOREIGN KEY([MaDP])
REFERENCES [dbo].[tDatPhong] ([MaDP])
GO
ALTER TABLE [dbo].[tChiTietDatPhong] CHECK CONSTRAINT [FK_tChiTietDatPhong_tDatPhong]
GO
ALTER TABLE [dbo].[tChiTietDatPhong]  WITH CHECK ADD  CONSTRAINT [FK_tChiTietDatPhong_tLoaiPhong] FOREIGN KEY([LoaiPhong])
REFERENCES [dbo].[tLoaiPhong] ([LoaiPhong])
GO
ALTER TABLE [dbo].[tChiTietDatPhong] CHECK CONSTRAINT [FK_tChiTietDatPhong_tLoaiPhong]
GO
ALTER TABLE [dbo].[tChiTietKH]  WITH CHECK ADD  CONSTRAINT [FK_tChiTietKH_tLoaiKhachHang] FOREIGN KEY([LoaiKH])
REFERENCES [dbo].[tLoaiKhachHang] ([LoaiKH])
GO
ALTER TABLE [dbo].[tChiTietKH] CHECK CONSTRAINT [FK_tChiTietKH_tLoaiKhachHang]
GO
ALTER TABLE [dbo].[tDangKy]  WITH CHECK ADD  CONSTRAINT [FK_tDangKy_tChiTietKH] FOREIGN KEY([MaKH])
REFERENCES [dbo].[tChiTietKH] ([MaKH])
GO
ALTER TABLE [dbo].[tDangKy] CHECK CONSTRAINT [FK_tDangKy_tChiTietKH]
GO
ALTER TABLE [dbo].[tDangKy]  WITH CHECK ADD  CONSTRAINT [FK_tDangKy_tSoPhong_LoaiPhong] FOREIGN KEY([SoPhong])
REFERENCES [dbo].[tSoPhong_LoaiPhong] ([SoPhong])
GO
ALTER TABLE [dbo].[tDangKy] CHECK CONSTRAINT [FK_tDangKy_tSoPhong_LoaiPhong]
GO
ALTER TABLE [dbo].[tDatPhong]  WITH CHECK ADD  CONSTRAINT [FK_tDatPhong_tChiTietKH] FOREIGN KEY([MaKH])
REFERENCES [dbo].[tChiTietKH] ([MaKH])
GO
ALTER TABLE [dbo].[tDatPhong] CHECK CONSTRAINT [FK_tDatPhong_tChiTietKH]
GO
ALTER TABLE [dbo].[tDoanhThu]  WITH CHECK ADD  CONSTRAINT [FK_tDoanhThu_tDangKy] FOREIGN KEY([MaDK])
REFERENCES [dbo].[tDangKy] ([MaDK])
GO
ALTER TABLE [dbo].[tDoanhThu] CHECK CONSTRAINT [FK_tDoanhThu_tDangKy]
GO
ALTER TABLE [dbo].[tSoPhong_LoaiPhong]  WITH CHECK ADD  CONSTRAINT [FK_tSoPhong_LoaiPhong_tLoaiPhong] FOREIGN KEY([LoaiPhong])
REFERENCES [dbo].[tLoaiPhong] ([LoaiPhong])
GO
ALTER TABLE [dbo].[tSoPhong_LoaiPhong] CHECK CONSTRAINT [FK_tSoPhong_LoaiPhong_tLoaiPhong]
GO
