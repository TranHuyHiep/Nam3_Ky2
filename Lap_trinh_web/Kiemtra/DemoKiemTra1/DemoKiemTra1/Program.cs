using DemoKiemTra1.Models;
using DemoKiemTra1.Repository;
using Microsoft.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddControllersWithViews();

// update
var connectionString = builder.Configuration.GetConnectionString("QlbongDaContext");
builder.Services.AddDbContext<QlbongDaContext>(x => x.UseSqlServer(connectionString));

builder.Services.AddScoped<ICauLacBoRepository, CauLacBoRepository>();


// done
var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}



app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();
