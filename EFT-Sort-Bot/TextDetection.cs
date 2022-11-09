using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Emgu.CV;
using Emgu.CV.Structure;

namespace EFT_Sort_Bot
{
    static class TextDetection
    {
        public static void DetectText(Image<Bgr, byte> img)
        {
            Image<Gray, byte> sobel = img.Convert<Gray,byte>().Sobel(1, 0, 3).AbsDiff(new Gray(0.0)).Convert<Gray, byte>().ThresholdBinary(new Gray(100), new Gray(255));
            Mat SE = CvInvoke.GetStructuringElement(Emgu.CV.CvEnum.ElementShape.Rectangle, new Size(10, 2), new Point(-1, -1));
            sobel = sobel.MorphologyEx(Emgu.CV.CvEnum.MorphOp.Dilate, SE, new Point(-1, -1), 1, Emgu.CV.CvEnum.BorderType.Reflect, new MCvScalar(255));
            Emgu.CV.Util.VectorOfVectorOfPoint conturs = new Emgu.CV.Util.VectorOfVectorOfPoint();
            Mat m = new Mat();

            CvInvoke.FindContours(sobel, conturs, m, Emgu.CV.CvEnum.RetrType.External, Emgu.CV.CvEnum.ChainApproxMethod.ChainApproxSimple);

            List<Rectangle> list = new List<Rectangle>();

            for (int i = 0; i < conturs.Size; i++)
            {
                Rectangle brect = CvInvoke.BoundingRectangle(conturs[i]);

                if (brect.Width>30 && brect.Height>8 && brect.Height < 100)
                {
                    list.Add(brect);
                }
            }

            Image<Bgr, byte> imgout = img.CopyBlank();
            foreach (var r in list)
            {
                CvInvoke.Rectangle(img, r, new MCvScalar(0, 0, 255), 2);
                CvInvoke.Rectangle(imgout, r, new MCvScalar(0, 255, 255), -1);
            }

            imgout._And(img); 
        }
    }
}
