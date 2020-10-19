.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240364_A3FAA4
/* A3FAA4 80240364 460C7301 */  sub.s     $f12, $f14, $f12
/* A3FAA8 80240368 44863000 */  mtc1      $a2, $f6
/* A3FAAC 8024036C 44800000 */  mtc1      $zero, $f0
/* A3FAB0 80240370 44872000 */  mtc1      $a3, $f4
/* A3FAB4 80240374 8FA20010 */  lw        $v0, 0x10($sp)
/* A3FAB8 80240378 460C003C */  c.lt.s    $f0, $f12
/* A3FABC 8024037C 00000000 */  nop       
/* A3FAC0 80240380 4500000F */  bc1f      .L802403C0
/* A3FAC4 80240384 46067081 */   sub.s    $f2, $f14, $f6
/* A3FAC8 80240388 4600103C */  c.lt.s    $f2, $f0
/* A3FACC 8024038C 00000000 */  nop       
/* A3FAD0 80240390 45000003 */  bc1f      .L802403A0
/* A3FAD4 80240394 00000000 */   nop      
.L80240398:
/* A3FAD8 80240398 03E00008 */  jr        $ra
/* A3FADC 8024039C E44E0000 */   swc1     $f14, ($v0)
.L802403A0:
/* A3FAE0 802403A0 4602203C */  c.lt.s    $f4, $f2
/* A3FAE4 802403A4 00000000 */  nop       
/* A3FAE8 802403A8 45000012 */  bc1f      .L802403F4
/* A3FAEC 802403AC 00000000 */   nop      
/* A3FAF0 802403B0 C4400000 */  lwc1      $f0, ($v0)
/* A3FAF4 802403B4 46040000 */  add.s     $f0, $f0, $f4
/* A3FAF8 802403B8 03E00008 */  jr        $ra
/* A3FAFC 802403BC E4400000 */   swc1     $f0, ($v0)
.L802403C0:
/* A3FB00 802403C0 4602003C */  c.lt.s    $f0, $f2
/* A3FB04 802403C4 00000000 */  nop       
/* A3FB08 802403C8 4501FFF3 */  bc1t      .L80240398
/* A3FB0C 802403CC 00000000 */   nop      
/* A3FB10 802403D0 46002007 */  neg.s     $f0, $f4
/* A3FB14 802403D4 4600103C */  c.lt.s    $f2, $f0
/* A3FB18 802403D8 00000000 */  nop       
/* A3FB1C 802403DC 45000005 */  bc1f      .L802403F4
/* A3FB20 802403E0 00000000 */   nop      
/* A3FB24 802403E4 C4400000 */  lwc1      $f0, ($v0)
/* A3FB28 802403E8 46040001 */  sub.s     $f0, $f0, $f4
/* A3FB2C 802403EC 03E00008 */  jr        $ra
/* A3FB30 802403F0 E4400000 */   swc1     $f0, ($v0)
.L802403F4:
/* A3FB34 802403F4 C4400000 */  lwc1      $f0, ($v0)
/* A3FB38 802403F8 46020000 */  add.s     $f0, $f0, $f2
/* A3FB3C 802403FC 03E00008 */  jr        $ra
/* A3FB40 80240400 E4400000 */   swc1     $f0, ($v0)
