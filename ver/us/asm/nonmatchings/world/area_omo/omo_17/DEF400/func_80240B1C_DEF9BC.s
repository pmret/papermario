.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B1C_DEF9BC
/* DEF9BC 80240B1C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DEF9C0 80240B20 AFB20018 */  sw        $s2, 0x18($sp)
/* DEF9C4 80240B24 0080902D */  daddu     $s2, $a0, $zero
/* DEF9C8 80240B28 AFBF001C */  sw        $ra, 0x1c($sp)
/* DEF9CC 80240B2C AFB10014 */  sw        $s1, 0x14($sp)
/* DEF9D0 80240B30 AFB00010 */  sw        $s0, 0x10($sp)
/* DEF9D4 80240B34 8E500148 */  lw        $s0, 0x148($s2)
/* DEF9D8 80240B38 0C00EABB */  jal       get_npc_unsafe
/* DEF9DC 80240B3C 86040008 */   lh       $a0, 8($s0)
/* DEF9E0 80240B40 8E03006C */  lw        $v1, 0x6c($s0)
/* DEF9E4 80240B44 24060001 */  addiu     $a2, $zero, 1
/* DEF9E8 80240B48 10660016 */  beq       $v1, $a2, .L80240BA4
/* DEF9EC 80240B4C 0040882D */   daddu    $s1, $v0, $zero
/* DEF9F0 80240B50 28620002 */  slti      $v0, $v1, 2
/* DEF9F4 80240B54 50400005 */  beql      $v0, $zero, .L80240B6C
/* DEF9F8 80240B58 24020002 */   addiu    $v0, $zero, 2
/* DEF9FC 80240B5C 10600009 */  beqz      $v1, .L80240B84
/* DEFA00 80240B60 3C02003C */   lui      $v0, 0x3c
/* DEFA04 80240B64 0809032C */  j         .L80240CB0
/* DEFA08 80240B68 24020004 */   addiu    $v0, $zero, 4
.L80240B6C:
/* DEFA0C 80240B6C 10620030 */  beq       $v1, $v0, .L80240C30
/* DEFA10 80240B70 24020003 */   addiu    $v0, $zero, 3
/* DEFA14 80240B74 10620034 */  beq       $v1, $v0, .L80240C48
/* DEFA18 80240B78 00000000 */   nop
/* DEFA1C 80240B7C 0809032A */  j         .L80240CA8
/* DEFA20 80240B80 00000000 */   nop
.L80240B84:
/* DEFA24 80240B84 3442000C */  ori       $v0, $v0, 0xc
/* DEFA28 80240B88 3C054387 */  lui       $a1, 0x4387
/* DEFA2C 80240B8C 0220202D */  daddu     $a0, $s1, $zero
/* DEFA30 80240B90 AE06006C */  sw        $a2, 0x6c($s0)
/* DEFA34 80240B94 AE000070 */  sw        $zero, 0x70($s0)
/* DEFA38 80240B98 0C00ECD0 */  jal       set_npc_yaw
/* DEFA3C 80240B9C AE220028 */   sw       $v0, 0x28($s1)
/* DEFA40 80240BA0 AE200048 */  sw        $zero, 0x48($s1)
.L80240BA4:
/* DEFA44 80240BA4 8E030070 */  lw        $v1, 0x70($s0)
/* DEFA48 80240BA8 04610002 */  bgez      $v1, .L80240BB4
/* DEFA4C 80240BAC 0060102D */   daddu    $v0, $v1, $zero
/* DEFA50 80240BB0 2462000F */  addiu     $v0, $v1, 0xf
.L80240BB4:
/* DEFA54 80240BB4 00022103 */  sra       $a0, $v0, 4
/* DEFA58 80240BB8 00041100 */  sll       $v0, $a0, 4
/* DEFA5C 80240BBC 00622023 */  subu      $a0, $v1, $v0
/* DEFA60 80240BC0 28820004 */  slti      $v0, $a0, 4
/* DEFA64 80240BC4 10400003 */  beqz      $v0, .L80240BD4
/* DEFA68 80240BC8 3C02003C */   lui      $v0, 0x3c
/* DEFA6C 80240BCC 08090303 */  j         .L80240C0C
/* DEFA70 80240BD0 3442000C */   ori      $v0, $v0, 0xc
.L80240BD4:
/* DEFA74 80240BD4 28820008 */  slti      $v0, $a0, 8
/* DEFA78 80240BD8 10400003 */  beqz      $v0, .L80240BE8
/* DEFA7C 80240BDC 3C02003C */   lui      $v0, 0x3c
/* DEFA80 80240BE0 08090303 */  j         .L80240C0C
/* DEFA84 80240BE4 3442000B */   ori      $v0, $v0, 0xb
.L80240BE8:
/* DEFA88 80240BE8 2882000C */  slti      $v0, $a0, 0xc
/* DEFA8C 80240BEC 10400003 */  beqz      $v0, .L80240BFC
/* DEFA90 80240BF0 3C02003C */   lui      $v0, 0x3c
/* DEFA94 80240BF4 08090303 */  j         .L80240C0C
/* DEFA98 80240BF8 3442000C */   ori      $v0, $v0, 0xc
.L80240BFC:
/* DEFA9C 80240BFC 28820010 */  slti      $v0, $a0, 0x10
/* DEFAA0 80240C00 10400003 */  beqz      $v0, .L80240C10
/* DEFAA4 80240C04 3C02003C */   lui      $v0, 0x3c
/* DEFAA8 80240C08 3442000D */  ori       $v0, $v0, 0xd
.L80240C0C:
/* DEFAAC 80240C0C AE220028 */  sw        $v0, 0x28($s1)
.L80240C10:
/* DEFAB0 80240C10 8E020070 */  lw        $v0, 0x70($s0)
/* DEFAB4 80240C14 24420001 */  addiu     $v0, $v0, 1
/* DEFAB8 80240C18 AE020070 */  sw        $v0, 0x70($s0)
/* DEFABC 80240C1C 28420041 */  slti      $v0, $v0, 0x41
/* DEFAC0 80240C20 14400021 */  bnez      $v0, .L80240CA8
/* DEFAC4 80240C24 24020002 */   addiu    $v0, $zero, 2
/* DEFAC8 80240C28 0809032A */  j         .L80240CA8
/* DEFACC 80240C2C AE02006C */   sw       $v0, 0x6c($s0)
.L80240C30:
/* DEFAD0 80240C30 3C03003C */  lui       $v1, 0x3c
/* DEFAD4 80240C34 3463000C */  ori       $v1, $v1, 0xc
/* DEFAD8 80240C38 AE02006C */  sw        $v0, 0x6c($s0)
/* DEFADC 80240C3C AE000070 */  sw        $zero, 0x70($s0)
/* DEFAE0 80240C40 AE200048 */  sw        $zero, 0x48($s1)
/* DEFAE4 80240C44 AE230028 */  sw        $v1, 0x28($s1)
.L80240C48:
/* DEFAE8 80240C48 C6200048 */  lwc1      $f0, 0x48($s1)
/* DEFAEC 80240C4C 3C018024 */  lui       $at, %hi(D_802477B0_DF6650)
/* DEFAF0 80240C50 D42277B0 */  ldc1      $f2, %lo(D_802477B0_DF6650)($at)
/* DEFAF4 80240C54 46000021 */  cvt.d.s   $f0, $f0
/* DEFAF8 80240C58 46220000 */  add.d     $f0, $f0, $f2
/* DEFAFC 80240C5C 3C018024 */  lui       $at, %hi(D_802477B8_DF6658)
/* DEFB00 80240C60 D42277B8 */  ldc1      $f2, %lo(D_802477B8_DF6658)($at)
/* DEFB04 80240C64 46200020 */  cvt.s.d   $f0, $f0
/* DEFB08 80240C68 E6200048 */  swc1      $f0, 0x48($s1)
/* DEFB0C 80240C6C 46000021 */  cvt.d.s   $f0, $f0
/* DEFB10 80240C70 4620103C */  c.lt.d    $f2, $f0
/* DEFB14 80240C74 00000000 */  nop
/* DEFB18 80240C78 45000004 */  bc1f      .L80240C8C
/* DEFB1C 80240C7C 00000000 */   nop
/* DEFB20 80240C80 46220001 */  sub.d     $f0, $f0, $f2
/* DEFB24 80240C84 46200020 */  cvt.s.d   $f0, $f0
/* DEFB28 80240C88 E6200048 */  swc1      $f0, 0x48($s1)
.L80240C8C:
/* DEFB2C 80240C8C 8E020070 */  lw        $v0, 0x70($s0)
/* DEFB30 80240C90 24420001 */  addiu     $v0, $v0, 1
/* DEFB34 80240C94 AE020070 */  sw        $v0, 0x70($s0)
/* DEFB38 80240C98 2842002E */  slti      $v0, $v0, 0x2e
/* DEFB3C 80240C9C 14400002 */  bnez      $v0, .L80240CA8
/* DEFB40 80240CA0 24020004 */   addiu    $v0, $zero, 4
/* DEFB44 80240CA4 AE02006C */  sw        $v0, 0x6c($s0)
.L80240CA8:
/* DEFB48 80240CA8 8E03006C */  lw        $v1, 0x6c($s0)
/* DEFB4C 80240CAC 24020004 */  addiu     $v0, $zero, 4
.L80240CB0:
/* DEFB50 80240CB0 14620005 */  bne       $v1, $v0, .L80240CC8
/* DEFB54 80240CB4 0220202D */   daddu    $a0, $s1, $zero
/* DEFB58 80240CB8 3C054387 */  lui       $a1, 0x4387
/* DEFB5C 80240CBC 0C00ECD0 */  jal       set_npc_yaw
/* DEFB60 80240CC0 AC800048 */   sw       $zero, 0x48($a0)
/* DEFB64 80240CC4 AE400070 */  sw        $zero, 0x70($s2)
.L80240CC8:
/* DEFB68 80240CC8 8FBF001C */  lw        $ra, 0x1c($sp)
/* DEFB6C 80240CCC 8FB20018 */  lw        $s2, 0x18($sp)
/* DEFB70 80240CD0 8FB10014 */  lw        $s1, 0x14($sp)
/* DEFB74 80240CD4 8FB00010 */  lw        $s0, 0x10($sp)
/* DEFB78 80240CD8 03E00008 */  jr        $ra
/* DEFB7C 80240CDC 27BD0020 */   addiu    $sp, $sp, 0x20
