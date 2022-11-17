import cv2
import numpy as np
import time

def find_match(big_image, small_image, threshold=0.7):
    start = time.time()
    img_rgb = cv2.imread(big_image)
    img_gray = cv2.cvtColor(img_rgb, cv2.COLOR_RGB2GRAY)
    template = cv2.imread(small_image, 0)
    res = cv2.matchTemplate(img_gray, template, cv2.TM_CCOEFF_NORMED)
    w, h = template.shape[::-1]
    loc = np.where(res >= threshold)
    out_list = []
    for pt in zip(*loc[::-1]):
        out_list.append([pt[0], pt[1]])
        cv2.rectangle(img_rgb, pt, (pt[0] + w, pt[1] + h), (0, 0, 255), 2)

    cv2.imwrite("res.png", img_rgb)

    print(time.time() - start)
    return [out_list, w, h]


print(find_match("NEW2.png", "BP.png"))
