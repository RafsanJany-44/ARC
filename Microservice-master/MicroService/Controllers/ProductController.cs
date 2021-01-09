using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using MicroService.Database;
using MicroService.Database.Entities;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

// For more information on enabling Web API for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace MicroService.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class ProductController : ControllerBase
    {
        DatabaseContext db;
        public ProductController()
        {
            db = new DatabaseContext();
        }
        // GET: api/product/list
        [HttpGet]
        public IEnumerable<product> list()
        {
            return db.products.ToList();
        }

        // GET api/product/5
        [HttpGet("{id}")]
        public product Get(int id)
        {
            return db.products.Find(id);
        }

        // POST api/product/add
        [HttpPost]
        public IActionResult add([FromBody] product value)
        {
            string output;
            try
            {
                db.products.Add(value);
                db.SaveChanges();
                output = value.Name + value.CategoryId;
                if (value != Get(value.Id))
                    return StatusCode(StatusCodes.Status201Created, output);
                else
                    return StatusCode(StatusCodes.Status400BadRequest, output);
            }
            catch (Exception e)
            {
                return StatusCode(StatusCodes.Status500InternalServerError, e);
            }
        }


        // PUT api/product/5
        [HttpPut("{id}")]
        public void updateCategory(int id, [FromBody] product value)
        {
            value.CategoryId = id;
            db.SaveChanges();
        }

        // DELETE api/remove/5
        [HttpDelete("{id}")]
        public void remove(int id)
        {
            db.products.Remove(Get(id));
            db.SaveChanges();
        }
    }
}
