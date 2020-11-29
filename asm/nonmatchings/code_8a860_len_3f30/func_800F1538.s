.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F1538
/* 8A9E8 800F1538 3C048011 */  lui       $a0, %hi(D_8010D65C)
/* 8A9EC 800F153C 8C84D65C */  lw        $a0, %lo(D_8010D65C)($a0)
/* 8A9F0 800F1540 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8A9F4 800F1544 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8A9F8 800F1548 AFB10014 */  sw        $s1, 0x14($sp)
/* 8A9FC 800F154C 0C05123D */  jal       free_icon
/* 8AA00 800F1550 AFB00010 */   sw       $s0, 0x10($sp)
/* 8AA04 800F1554 3C048011 */  lui       $a0, %hi(D_8010D678)
/* 8AA08 800F1558 8C84D678 */  lw        $a0, %lo(D_8010D678)($a0)
/* 8AA0C 800F155C 0C05123D */  jal       free_icon
/* 8AA10 800F1560 00000000 */   nop      
/* 8AA14 800F1564 3C048011 */  lui       $a0, %hi(D_8010D66C)
/* 8AA18 800F1568 8C84D66C */  lw        $a0, %lo(D_8010D66C)($a0)
/* 8AA1C 800F156C 0C05123D */  jal       free_icon
/* 8AA20 800F1570 00000000 */   nop      
/* 8AA24 800F1574 3C048011 */  lui       $a0, %hi(D_8010D670)
/* 8AA28 800F1578 8C84D670 */  lw        $a0, %lo(D_8010D670)($a0)
/* 8AA2C 800F157C 0C05123D */  jal       free_icon
/* 8AA30 800F1580 00000000 */   nop      
/* 8AA34 800F1584 3C048011 */  lui       $a0, %hi(D_8010D674)
/* 8AA38 800F1588 8C84D674 */  lw        $a0, %lo(D_8010D674)($a0)
/* 8AA3C 800F158C 0C05123D */  jal       free_icon
/* 8AA40 800F1590 00000000 */   nop      
/* 8AA44 800F1594 3C108011 */  lui       $s0, %hi(D_8010D69C)
/* 8AA48 800F1598 2610D69C */  addiu     $s0, $s0, %lo(D_8010D69C)
/* 8AA4C 800F159C 8E020000 */  lw        $v0, ($s0)
/* 8AA50 800F15A0 8C430318 */  lw        $v1, 0x318($v0)
/* 8AA54 800F15A4 24020003 */  addiu     $v0, $zero, 3
/* 8AA58 800F15A8 14620009 */  bne       $v1, $v0, .L800F15D0
/* 8AA5C 800F15AC 00000000 */   nop      
/* 8AA60 800F15B0 3C048011 */  lui       $a0, %hi(D_8010D660)
/* 8AA64 800F15B4 8C84D660 */  lw        $a0, %lo(D_8010D660)($a0)
/* 8AA68 800F15B8 0C05123D */  jal       free_icon
/* 8AA6C 800F15BC 00000000 */   nop      
/* 8AA70 800F15C0 3C048011 */  lui       $a0, %hi(D_8010D664)
/* 8AA74 800F15C4 8C84D664 */  lw        $a0, %lo(D_8010D664)($a0)
/* 8AA78 800F15C8 0C05123D */  jal       free_icon
/* 8AA7C 800F15CC 00000000 */   nop      
.L800F15D0:
/* 8AA80 800F15D0 8E020000 */  lw        $v0, ($s0)
/* 8AA84 800F15D4 8C420318 */  lw        $v0, 0x318($v0)
/* 8AA88 800F15D8 24110004 */  addiu     $s1, $zero, 4
/* 8AA8C 800F15DC 14510009 */  bne       $v0, $s1, .L800F1604
/* 8AA90 800F15E0 00000000 */   nop      
/* 8AA94 800F15E4 3C048011 */  lui       $a0, %hi(D_8010D660)
/* 8AA98 800F15E8 8C84D660 */  lw        $a0, %lo(D_8010D660)($a0)
/* 8AA9C 800F15EC 0C05123D */  jal       free_icon
/* 8AAA0 800F15F0 00000000 */   nop      
/* 8AAA4 800F15F4 3C048011 */  lui       $a0, %hi(D_8010D664)
/* 8AAA8 800F15F8 8C84D664 */  lw        $a0, %lo(D_8010D664)($a0)
/* 8AAAC 800F15FC 0C05123D */  jal       free_icon
/* 8AAB0 800F1600 00000000 */   nop      
.L800F1604:
/* 8AAB4 800F1604 8E020000 */  lw        $v0, ($s0)
/* 8AAB8 800F1608 8C430318 */  lw        $v1, 0x318($v0)
/* 8AABC 800F160C 24020001 */  addiu     $v0, $zero, 1
/* 8AAC0 800F1610 10620003 */  beq       $v1, $v0, .L800F1620
/* 8AAC4 800F1614 00000000 */   nop      
/* 8AAC8 800F1618 14710005 */  bne       $v1, $s1, .L800F1630
/* 8AACC 800F161C 00000000 */   nop      
.L800F1620:
/* 8AAD0 800F1620 3C048011 */  lui       $a0, %hi(D_8010D668)
/* 8AAD4 800F1624 8C84D668 */  lw        $a0, %lo(D_8010D668)($a0)
/* 8AAD8 800F1628 0C05123D */  jal       free_icon
/* 8AADC 800F162C 00000000 */   nop      
.L800F1630:
/* 8AAE0 800F1630 3C108011 */  lui       $s0, %hi(D_8010D69C)
/* 8AAE4 800F1634 2610D69C */  addiu     $s0, $s0, %lo(D_8010D69C)
/* 8AAE8 800F1638 8E020000 */  lw        $v0, ($s0)
/* 8AAEC 800F163C 8C430318 */  lw        $v1, 0x318($v0)
/* 8AAF0 800F1640 24020005 */  addiu     $v0, $zero, 5
/* 8AAF4 800F1644 14620005 */  bne       $v1, $v0, .L800F165C
/* 8AAF8 800F1648 00000000 */   nop      
/* 8AAFC 800F164C 3C048011 */  lui       $a0, %hi(D_8010D660)
/* 8AB00 800F1650 8C84D660 */  lw        $a0, %lo(D_8010D660)($a0)
/* 8AB04 800F1654 0C05123D */  jal       free_icon
/* 8AB08 800F1658 00000000 */   nop      
.L800F165C:
/* 8AB0C 800F165C 8E020000 */  lw        $v0, ($s0)
/* 8AB10 800F1660 8C430318 */  lw        $v1, 0x318($v0)
/* 8AB14 800F1664 28620005 */  slti      $v0, $v1, 5
/* 8AB18 800F1668 14400003 */  bnez      $v0, .L800F1678
/* 8AB1C 800F166C 2402000C */   addiu    $v0, $zero, 0xc
/* 8AB20 800F1670 1462000E */  bne       $v1, $v0, .L800F16AC
/* 8AB24 800F1674 00000000 */   nop      
.L800F1678:
/* 8AB28 800F1678 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8AB2C 800F167C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8AB30 800F1680 80420070 */  lb        $v0, 0x70($v0)
/* 8AB34 800F1684 14400009 */  bnez      $v0, .L800F16AC
/* 8AB38 800F1688 00000000 */   nop      
/* 8AB3C 800F168C 3C028011 */  lui       $v0, %hi(D_8010D69A)
/* 8AB40 800F1690 8042D69A */  lb        $v0, %lo(D_8010D69A)($v0)
/* 8AB44 800F1694 14400003 */  bnez      $v0, .L800F16A4
/* 8AB48 800F1698 00000000 */   nop      
/* 8AB4C 800F169C 0C03A631 */  jal       func_800E98C4
/* 8AB50 800F16A0 00000000 */   nop      
.L800F16A4:
/* 8AB54 800F16A4 0C03A5EE */  jal       func_800E97B8
/* 8AB58 800F16A8 00000000 */   nop      
.L800F16AC:
/* 8AB5C 800F16AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8AB60 800F16B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 8AB64 800F16B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8AB68 800F16B8 2402FFFC */  addiu     $v0, $zero, -4
/* 8AB6C 800F16BC 3C018011 */  lui       $at, %hi(D_8010D640)
/* 8AB70 800F16C0 AC22D640 */  sw        $v0, %lo(D_8010D640)($at)
/* 8AB74 800F16C4 03E00008 */  jr        $ra
/* 8AB78 800F16C8 27BD0020 */   addiu    $sp, $sp, 0x20
