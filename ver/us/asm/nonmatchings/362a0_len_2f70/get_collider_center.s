.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_collider_center
/* 37210 8005BE10 000410C0 */  sll       $v0, $a0, 3
/* 37214 8005BE14 00441023 */  subu      $v0, $v0, $a0
/* 37218 8005BE18 3C03800B */  lui       $v1, %hi(gCollisionData+0x4)
/* 3721C 8005BE1C 8C6342E4 */  lw        $v1, %lo(gCollisionData+0x4)($v1)
/* 37220 8005BE20 00021080 */  sll       $v0, $v0, 2
/* 37224 8005BE24 00431021 */  addu      $v0, $v0, $v1
/* 37228 8005BE28 8C420010 */  lw        $v0, 0x10($v0)
/* 3722C 8005BE2C C4400000 */  lwc1      $f0, ($v0)
/* 37230 8005BE30 C442000C */  lwc1      $f2, 0xc($v0)
/* 37234 8005BE34 46020000 */  add.s     $f0, $f0, $f2
/* 37238 8005BE38 3C013F00 */  lui       $at, 0x3f00
/* 3723C 8005BE3C 44812000 */  mtc1      $at, $f4
/* 37240 8005BE40 00000000 */  nop
/* 37244 8005BE44 46040002 */  mul.s     $f0, $f0, $f4
/* 37248 8005BE48 00000000 */  nop
/* 3724C 8005BE4C E4A00000 */  swc1      $f0, ($a1)
/* 37250 8005BE50 C4400004 */  lwc1      $f0, 4($v0)
/* 37254 8005BE54 C4420010 */  lwc1      $f2, 0x10($v0)
/* 37258 8005BE58 46020000 */  add.s     $f0, $f0, $f2
/* 3725C 8005BE5C 46040002 */  mul.s     $f0, $f0, $f4
/* 37260 8005BE60 00000000 */  nop
/* 37264 8005BE64 E4C00000 */  swc1      $f0, ($a2)
/* 37268 8005BE68 C4400008 */  lwc1      $f0, 8($v0)
/* 3726C 8005BE6C C4420014 */  lwc1      $f2, 0x14($v0)
/* 37270 8005BE70 46020000 */  add.s     $f0, $f0, $f2
/* 37274 8005BE74 46040002 */  mul.s     $f0, $f0, $f4
/* 37278 8005BE78 00000000 */  nop
/* 3727C 8005BE7C 03E00008 */  jr        $ra
/* 37280 8005BE80 E4E00000 */   swc1     $f0, ($a3)
