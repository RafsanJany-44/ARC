using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace MicroService.Database.Entities
{
    public class product
    { 
        public int Id { get; set; }
        public string Name { get; set; }
        public int CategoryId { get; set; }
        public int Price { get; set; }
        public float AverageRating { get; set; }
        public int SaleCount { get; set; }
    }
}
