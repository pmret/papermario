.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422C0_CCD5D0
/* CCD5D0 802422C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CCD5D4 802422C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* CCD5D8 802422C8 8C82000C */  lw        $v0, 0xc($a0)
/* CCD5DC 802422CC 0C0B1EAF */  jal       get_variable
/* CCD5E0 802422D0 8C450000 */   lw       $a1, ($v0)
/* CCD5E4 802422D4 0040182D */  daddu     $v1, $v0, $zero
/* CCD5E8 802422D8 10600012 */  beqz      $v1, .L80242324
/* CCD5EC 802422DC 0000202D */   daddu    $a0, $zero, $zero
/* CCD5F0 802422E0 8C620000 */  lw        $v0, ($v1)
/* CCD5F4 802422E4 5040000A */  beql      $v0, $zero, .L80242310
/* CCD5F8 802422E8 00041080 */   sll      $v0, $a0, 2
/* CCD5FC 802422EC 3C058024 */  lui       $a1, %hi(D_802453B0)
/* CCD600 802422F0 24A553B0 */  addiu     $a1, $a1, %lo(D_802453B0)
.L802422F4:
/* CCD604 802422F4 24630004 */  addiu     $v1, $v1, 4
/* CCD608 802422F8 24840001 */  addiu     $a0, $a0, 1
/* CCD60C 802422FC ACA20000 */  sw        $v0, ($a1)
/* CCD610 80242300 8C620000 */  lw        $v0, ($v1)
/* CCD614 80242304 1440FFFB */  bnez      $v0, .L802422F4
/* CCD618 80242308 24A50004 */   addiu    $a1, $a1, 4
/* CCD61C 8024230C 00041080 */  sll       $v0, $a0, 2
.L80242310:
/* CCD620 80242310 3C018024 */  lui       $at, %hi(D_802453B0)
/* CCD624 80242314 00220821 */  addu      $at, $at, $v0
/* CCD628 80242318 AC2053B0 */  sw        $zero, %lo(D_802453B0)($at)
/* CCD62C 8024231C 080908D3 */  j         .L8024234C
/* CCD630 80242320 00000000 */   nop
.L80242324:
/* CCD634 80242324 3C038024 */  lui       $v1, %hi(D_802453B0)
/* CCD638 80242328 246353B0 */  addiu     $v1, $v1, %lo(D_802453B0)
/* CCD63C 8024232C 0060282D */  daddu     $a1, $v1, $zero
.L80242330:
/* CCD640 80242330 24820080 */  addiu     $v0, $a0, 0x80
/* CCD644 80242334 AC620000 */  sw        $v0, ($v1)
/* CCD648 80242338 24630004 */  addiu     $v1, $v1, 4
/* CCD64C 8024233C 24840001 */  addiu     $a0, $a0, 1
/* CCD650 80242340 2882005B */  slti      $v0, $a0, 0x5b
/* CCD654 80242344 1440FFFA */  bnez      $v0, .L80242330
/* CCD658 80242348 ACA0016C */   sw       $zero, 0x16c($a1)
.L8024234C:
/* CCD65C 8024234C 8FBF0010 */  lw        $ra, 0x10($sp)
/* CCD660 80242350 24020002 */  addiu     $v0, $zero, 2
/* CCD664 80242354 03E00008 */  jr        $ra
/* CCD668 80242358 27BD0018 */   addiu    $sp, $sp, 0x18
/* CCD66C 8024235C 00000000 */  nop
