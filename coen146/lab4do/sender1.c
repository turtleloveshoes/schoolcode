Sb = 0
Sm = N – 1

Repeat the following steps forever:

1. If you receive a request number where Rn > Sb 
        Sm = Sm + (Rn – Sb)
        Sb = Rn

2.  If no packet is in transmission, 
        Transmit a packet where Sb <= Sn <= Sm.  
        Packets are transmitted in order.

