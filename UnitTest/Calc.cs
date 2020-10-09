using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UnitTest
{
    class Calc
    {
        private int TP, FP, TN, FN, P, N;

        public Calc(string TP, string FP, string TN, string FN)
        {
            bool tp = TP.Any(x => char.IsLetter(x));
            bool fp = FP.Any(x => char.IsLetter(x));
            bool tn = TN.Any(x => char.IsLetter(x));
            bool fn = FN.Any(x => char.IsLetter(x));

            if (TP == "" || FP == "" || TN == "" || FN == "")
            {
                this.TP = 0;
                this.TN = 0;
                this.FP = 0;
                this.FN = 0;
                P = 0;
                N = 0;
            }
            else if (tp == true || fp == true || tn == true || fn == true)
            {
                this.TP = -1;
                this.TN = -1;
                this.FP = -1;
                this.FN = -1;
                P = -1;
                N = -1;
            }
            else
            {
                this.TP = int.Parse(TP);
                this.TN = int.Parse(TN);
                this.FP = int.Parse(FP);
                this.FN = int.Parse(FN);
                P = int.Parse(TP) + int.Parse(FN);
                N = int.Parse(TN) + int.Parse(FP);
            }
        }

        public float precision()
        {
            if (TP == 0 || FP == 0 || TN == 0 || FN == 0)
            {
                return 0.0f;
            }
            else if (TP == -1 || FP == -1 || TN == -1 || FN == -1)
            {
                return -1.0f;
            }
            else
                return TP / (float)(TP + FP);
        }

        public float accuracy()
        {
            if (TP == 0 || FP == 0 || TN == 0 || FN == 0)
            {
                return 0.0f;
            }
            else if (TP == -1 || FP == -1 || TN == -1 || FN == -1)
            {
                return -1.0f;
            }
            else
                return (TP + TN) / (float)(P + N);
        }

        public float sensitivity()
        {
            if (TP == 0 || FP == 0 || TN == 0 || FN == 0)
            {
                return 0.0f;
            }
            else if (TP == -1 || FP == -1 || TN == -1 || FN == -1)
            {
                return -1.0f;
            }
            else
                return TP / (float)(TP + FN);
        }

        public float specificity()
        {
            if (TP == 0 || FP == 0 || TN == 0 || FN == 0)
            {
                return 0.0f;
            }
            else if (TP == -1 || FP == -1 || TN == -1 || FN == -1)
            {
                return -1.0f;
            }
            else
                return TN / (float)(FP + TN);
        }

        public float f1Score()
        {
            if (TP == 0 || FP == 0 || TN == 0 || FN == 0)
            {
                return 0.0f;
            }
            else if (TP == -1 || FP == -1 || TN == -1 || FN == -1)
            {
                return -1.0f;
            }
            else
                return 2 * TP / (float)(2 * TP + FP + FN);
        }

    }
}
