/*N-window size
Rn = request number
Sn = sequence number
Sb = sequence base
Sm = sequence max

Receiver:

Rn = 0

Do the following forever:

If the packet received = Rn && the packet is error free
        Accept the packet and send it to a higher layer
        Rn = Rn + 1
        Send a Request for Rn
Else
        Refuse packet
        Send a Request for*/
