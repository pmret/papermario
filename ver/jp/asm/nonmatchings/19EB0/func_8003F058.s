.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F058
/* 1A458 8003F058 3C038007 */  lui       $v1, %hi(D_800773E0)
/* 1A45C 8003F05C 8C6373E0 */  lw        $v1, %lo(D_800773E0)($v1)
/* 1A460 8003F060 3C05800B */  lui       $a1, %hi(D_800B1D60)
/* 1A464 8003F064 24A51D60 */  addiu     $a1, $a1, %lo(D_800B1D60)
/* 1A468 8003F068 00031080 */  sll       $v0, $v1, 2
/* 1A46C 8003F06C 00431021 */  addu      $v0, $v0, $v1
/* 1A470 8003F070 00021080 */  sll       $v0, $v0, 2
/* 1A474 8003F074 00431023 */  subu      $v0, $v0, $v1
/* 1A478 8003F078 000218C0 */  sll       $v1, $v0, 3
/* 1A47C 8003F07C 00431021 */  addu      $v0, $v0, $v1
/* 1A480 8003F080 000210C0 */  sll       $v0, $v0, 3
/* 1A484 8003F084 00451021 */  addu      $v0, $v0, $a1
/* 1A488 8003F088 C4400048 */  lwc1      $f0, 0x48($v0)
/* 1A48C 8003F08C 4600008D */  trunc.w.s $f2, $f0
/* 1A490 8003F090 E4820084 */  swc1      $f2, 0x84($a0)
/* 1A494 8003F094 C440004C */  lwc1      $f0, 0x4c($v0)
/* 1A498 8003F098 4600008D */  trunc.w.s $f2, $f0
/* 1A49C 8003F09C E4820088 */  swc1      $f2, 0x88($a0)
/* 1A4A0 8003F0A0 C4400050 */  lwc1      $f0, 0x50($v0)
/* 1A4A4 8003F0A4 4600008D */  trunc.w.s $f2, $f0
/* 1A4A8 8003F0A8 E482008C */  swc1      $f2, 0x8c($a0)
/* 1A4AC 8003F0AC 03E00008 */  jr        $ra
/* 1A4B0 8003F0B0 24020002 */   addiu    $v0, $zero, 2
