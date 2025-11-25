from PIL import Image
import numpy as np
import matplotlib.pyplot as plt


def steg_process():

    # load and convert to gray
    c = Image.open("1.jpg").convert("L")
    s = Image.open("2.jpg").convert("L")

    # resizing the secret so that both match
    s = s.resize(c.size)

    cover = np.array(c)
    secret = np.array(s)

    # ---- hiding part ----

    # take upper 4 bits of secret
    # (instead of direct mask I divide by 16)
    secret_part = (secret // 16)

    # clear last 4 bits of cover
    # (multiply by 16 drops lower nibble)
    cover_part = (cover // 16) * 16

    # combine both
    stego = cover_part + secret_part

    # ---- extraction part ----

    # to extract, take last 4 bits (mod 16), then multiply back
    recovered = (stego % 16) * 16

    # convert arrays back to images
    cover_img = Image.fromarray(cover)
    secret_img = Image.fromarray(secret)
    stego_img = Image.fromarray(stego.astype(np.uint8))
    extracted_img = Image.fromarray(recovered.astype(np.uint8))

    # ---- show all results ----
    plt.figure(figsize=(12, 8))

    plt.subplot(2, 2, 1)
    plt.title("Cover Gray")
    plt.imshow(cover_img, cmap='gray')
    plt.axis("off")

    plt.subplot(2, 2, 2)
    plt.title("Secret Gray")
    plt.imshow(secret_img, cmap='gray')
    plt.axis("off")

    plt.subplot(2, 2, 3)
    plt.title("Stego (after hiding)")
    plt.imshow(stego_img, cmap='gray')
    plt.axis("off")

    plt.subplot(2, 2, 4)
    plt.title("Extracted Image")
    plt.imshow(extracted_img, cmap='gray')
    plt.axis("off")

    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    steg_process()
