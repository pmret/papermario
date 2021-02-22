.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002E178
/* 9578 8002E178 3C08800B */  lui       $t0, %hi(D_800B1D60)
/* 957C 8002E17C 25081D60 */  addiu     $t0, $t0, %lo(D_800B1D60)
/* 9580 8002E180 00041080 */  sll       $v0, $a0, 2
/* 9584 8002E184 00441021 */  addu      $v0, $v0, $a0
/* 9588 8002E188 00021080 */  sll       $v0, $v0, 2
/* 958C 8002E18C 00441023 */  subu      $v0, $v0, $a0
/* 9590 8002E190 000218C0 */  sll       $v1, $v0, 3
/* 9594 8002E194 00431021 */  addu      $v0, $v0, $v1
/* 9598 8002E198 000210C0 */  sll       $v0, $v0, 3
/* 959C 8002E19C 00481021 */  addu      $v0, $v0, $t0
/* 95A0 8002E1A0 9443000A */  lhu       $v1, 0xa($v0)
/* 95A4 8002E1A4 8FA40010 */  lw        $a0, 0x10($sp)
/* 95A8 8002E1A8 A4E30000 */  sh        $v1, ($a3)
/* 95AC 8002E1AC 9443000C */  lhu       $v1, 0xc($v0)
/* 95B0 8002E1B0 A4830000 */  sh        $v1, ($a0)
/* 95B4 8002E1B4 9443000E */  lhu       $v1, 0xe($v0)
/* 95B8 8002E1B8 A4A30000 */  sh        $v1, ($a1)
/* 95BC 8002E1BC 94420010 */  lhu       $v0, 0x10($v0)
/* 95C0 8002E1C0 03E00008 */  jr        $ra
/* 95C4 8002E1C4 A4C20000 */   sh       $v0, ($a2)
