.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AAC_B9E40C
/* B9E40C 80240AAC 27BDFF90 */  addiu     $sp, $sp, -0x70
/* B9E410 80240AB0 AFB40050 */  sw        $s4, 0x50($sp)
/* B9E414 80240AB4 0080A02D */  daddu     $s4, $a0, $zero
/* B9E418 80240AB8 AFBF0060 */  sw        $ra, 0x60($sp)
/* B9E41C 80240ABC AFB7005C */  sw        $s7, 0x5c($sp)
/* B9E420 80240AC0 AFB60058 */  sw        $s6, 0x58($sp)
/* B9E424 80240AC4 AFB50054 */  sw        $s5, 0x54($sp)
/* B9E428 80240AC8 AFB3004C */  sw        $s3, 0x4c($sp)
/* B9E42C 80240ACC AFB20048 */  sw        $s2, 0x48($sp)
/* B9E430 80240AD0 AFB10044 */  sw        $s1, 0x44($sp)
/* B9E434 80240AD4 AFB00040 */  sw        $s0, 0x40($sp)
/* B9E438 80240AD8 F7B40068 */  sdc1      $f20, 0x68($sp)
/* B9E43C 80240ADC 8E950148 */  lw        $s5, 0x148($s4)
/* B9E440 80240AE0 00A0B02D */  daddu     $s6, $a1, $zero
/* B9E444 80240AE4 86A40008 */  lh        $a0, 8($s5)
/* B9E448 80240AE8 0C00EABB */  jal       get_npc_unsafe
/* B9E44C 80240AEC 00C0B82D */   daddu    $s7, $a2, $zero
/* B9E450 80240AF0 0040982D */  daddu     $s3, $v0, $zero
/* B9E454 80240AF4 C6600018 */  lwc1      $f0, 0x18($s3)
/* B9E458 80240AF8 44801000 */  mtc1      $zero, $f2
/* B9E45C 80240AFC 44801800 */  mtc1      $zero, $f3
/* B9E460 80240B00 46000021 */  cvt.d.s   $f0, $f0
/* B9E464 80240B04 4620103C */  c.lt.d    $f2, $f0
/* B9E468 80240B08 00000000 */  nop       
/* B9E46C 80240B0C 45000021 */  bc1f      .L80240B94
/* B9E470 80240B10 27A50028 */   addiu    $a1, $sp, 0x28
/* B9E474 80240B14 C6600038 */  lwc1      $f0, 0x38($s3)
/* B9E478 80240B18 C662003C */  lwc1      $f2, 0x3c($s3)
/* B9E47C 80240B1C C6640040 */  lwc1      $f4, 0x40($s3)
/* B9E480 80240B20 C6660018 */  lwc1      $f6, 0x18($s3)
/* B9E484 80240B24 E7A00028 */  swc1      $f0, 0x28($sp)
/* B9E488 80240B28 E7A2002C */  swc1      $f2, 0x2c($sp)
/* B9E48C 80240B2C E7A40030 */  swc1      $f4, 0x30($sp)
/* B9E490 80240B30 E7A60010 */  swc1      $f6, 0x10($sp)
/* B9E494 80240B34 C660000C */  lwc1      $f0, 0xc($s3)
/* B9E498 80240B38 E7A00014 */  swc1      $f0, 0x14($sp)
/* B9E49C 80240B3C 866200A8 */  lh        $v0, 0xa8($s3)
/* B9E4A0 80240B40 44820000 */  mtc1      $v0, $f0
/* B9E4A4 80240B44 00000000 */  nop       
/* B9E4A8 80240B48 46800020 */  cvt.s.w   $f0, $f0
/* B9E4AC 80240B4C E7A00018 */  swc1      $f0, 0x18($sp)
/* B9E4B0 80240B50 866200A6 */  lh        $v0, 0xa6($s3)
/* B9E4B4 80240B54 27A6002C */  addiu     $a2, $sp, 0x2c
/* B9E4B8 80240B58 44820000 */  mtc1      $v0, $f0
/* B9E4BC 80240B5C 00000000 */  nop       
/* B9E4C0 80240B60 46800020 */  cvt.s.w   $f0, $f0
/* B9E4C4 80240B64 E7A0001C */  swc1      $f0, 0x1c($sp)
/* B9E4C8 80240B68 8E640080 */  lw        $a0, 0x80($s3)
/* B9E4CC 80240B6C 0C037711 */  jal       func_800DDC44
/* B9E4D0 80240B70 27A70030 */   addiu    $a3, $sp, 0x30
/* B9E4D4 80240B74 10400003 */  beqz      $v0, .L80240B84
/* B9E4D8 80240B78 00000000 */   nop      
/* B9E4DC 80240B7C 080902E5 */  j         .L80240B94
/* B9E4E0 80240B80 AE600018 */   sw       $zero, 0x18($s3)
.L80240B84:
/* B9E4E4 80240B84 8E650018 */  lw        $a1, 0x18($s3)
/* B9E4E8 80240B88 8E66000C */  lw        $a2, 0xc($s3)
/* B9E4EC 80240B8C 0C00EA95 */  jal       npc_move_heading
/* B9E4F0 80240B90 0260202D */   daddu    $a0, $s3, $zero
.L80240B94:
/* B9E4F4 80240B94 C660001C */  lwc1      $f0, 0x1c($s3)
/* B9E4F8 80240B98 44801000 */  mtc1      $zero, $f2
/* B9E4FC 80240B9C 44801800 */  mtc1      $zero, $f3
/* B9E500 80240BA0 46000021 */  cvt.d.s   $f0, $f0
/* B9E504 80240BA4 4622003C */  c.lt.d    $f0, $f2
/* B9E508 80240BA8 00000000 */  nop       
/* B9E50C 80240BAC 4500006C */  bc1f      .L80240D60
/* B9E510 80240BB0 27B00028 */   addiu    $s0, $sp, 0x28
/* B9E514 80240BB4 0200282D */  daddu     $a1, $s0, $zero
/* B9E518 80240BB8 27A60034 */  addiu     $a2, $sp, 0x34
/* B9E51C 80240BBC 27B20038 */  addiu     $s2, $sp, 0x38
/* B9E520 80240BC0 C6600038 */  lwc1      $f0, 0x38($s3)
/* B9E524 80240BC4 3C0142C8 */  lui       $at, 0x42c8
/* B9E528 80240BC8 44811000 */  mtc1      $at, $f2
/* B9E52C 80240BCC C6640040 */  lwc1      $f4, 0x40($s3)
/* B9E530 80240BD0 3C01447A */  lui       $at, 0x447a
/* B9E534 80240BD4 44813000 */  mtc1      $at, $f6
/* B9E538 80240BD8 27B10030 */  addiu     $s1, $sp, 0x30
/* B9E53C 80240BDC E7A00028 */  swc1      $f0, 0x28($sp)
/* B9E540 80240BE0 E7A20034 */  swc1      $f2, 0x34($sp)
/* B9E544 80240BE4 E7A40030 */  swc1      $f4, 0x30($sp)
/* B9E548 80240BE8 E7A60038 */  swc1      $f6, 0x38($sp)
/* B9E54C 80240BEC AFB20010 */  sw        $s2, 0x10($sp)
/* B9E550 80240BF0 8E640080 */  lw        $a0, 0x80($s3)
/* B9E554 80240BF4 0C0372DF */  jal       func_800DCB7C
/* B9E558 80240BF8 0220382D */   daddu    $a3, $s1, $zero
/* B9E55C 80240BFC 0200282D */  daddu     $a1, $s0, $zero
/* B9E560 80240C00 27A6002C */  addiu     $a2, $sp, 0x2c
/* B9E564 80240C04 C662003C */  lwc1      $f2, 0x3c($s3)
/* B9E568 80240C08 C6660038 */  lwc1      $f6, 0x38($s3)
/* B9E56C 80240C0C 3C01402A */  lui       $at, 0x402a
/* B9E570 80240C10 4481A800 */  mtc1      $at, $f21
/* B9E574 80240C14 4480A000 */  mtc1      $zero, $f20
/* B9E578 80240C18 460010A1 */  cvt.d.s   $f2, $f2
/* B9E57C 80240C1C 46341080 */  add.d     $f2, $f2, $f20
/* B9E580 80240C20 C660001C */  lwc1      $f0, 0x1c($s3)
/* B9E584 80240C24 C6640040 */  lwc1      $f4, 0x40($s3)
/* B9E588 80240C28 46000005 */  abs.s     $f0, $f0
/* B9E58C 80240C2C E7A40030 */  swc1      $f4, 0x30($sp)
/* B9E590 80240C30 3C014030 */  lui       $at, 0x4030
/* B9E594 80240C34 44812800 */  mtc1      $at, $f5
/* B9E598 80240C38 44802000 */  mtc1      $zero, $f4
/* B9E59C 80240C3C 46000021 */  cvt.d.s   $f0, $f0
/* B9E5A0 80240C40 E7A60028 */  swc1      $f6, 0x28($sp)
/* B9E5A4 80240C44 46240000 */  add.d     $f0, $f0, $f4
/* B9E5A8 80240C48 462010A0 */  cvt.s.d   $f2, $f2
/* B9E5AC 80240C4C E7A2002C */  swc1      $f2, 0x2c($sp)
/* B9E5B0 80240C50 46200020 */  cvt.s.d   $f0, $f0
/* B9E5B4 80240C54 E7A00038 */  swc1      $f0, 0x38($sp)
/* B9E5B8 80240C58 AFB20010 */  sw        $s2, 0x10($sp)
/* B9E5BC 80240C5C 8E640080 */  lw        $a0, 0x80($s3)
/* B9E5C0 80240C60 0C0372DF */  jal       func_800DCB7C
/* B9E5C4 80240C64 0220382D */   daddu    $a3, $s1, $zero
/* B9E5C8 80240C68 1040003D */  beqz      $v0, .L80240D60
/* B9E5CC 80240C6C 00000000 */   nop      
/* B9E5D0 80240C70 C660001C */  lwc1      $f0, 0x1c($s3)
/* B9E5D4 80240C74 C7A20038 */  lwc1      $f2, 0x38($sp)
/* B9E5D8 80240C78 46000005 */  abs.s     $f0, $f0
/* B9E5DC 80240C7C 46000021 */  cvt.d.s   $f0, $f0
/* B9E5E0 80240C80 46340000 */  add.d     $f0, $f0, $f20
/* B9E5E4 80240C84 460010A1 */  cvt.d.s   $f2, $f2
/* B9E5E8 80240C88 4620103E */  c.le.d    $f2, $f0
/* B9E5EC 80240C8C 00000000 */  nop       
/* B9E5F0 80240C90 45000033 */  bc1f      .L80240D60
/* B9E5F4 80240C94 2403F7FF */   addiu    $v1, $zero, -0x801
/* B9E5F8 80240C98 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* B9E5FC 80240C9C 8E620000 */  lw        $v0, ($s3)
/* B9E600 80240CA0 AE60001C */  sw        $zero, 0x1c($s3)
/* B9E604 80240CA4 00431024 */  and       $v0, $v0, $v1
/* B9E608 80240CA8 E660003C */  swc1      $f0, 0x3c($s3)
/* B9E60C 80240CAC AE620000 */  sw        $v0, ($s3)
/* B9E610 80240CB0 AFA00010 */  sw        $zero, 0x10($sp)
/* B9E614 80240CB4 AFA00014 */  sw        $zero, 0x14($sp)
/* B9E618 80240CB8 8E650038 */  lw        $a1, 0x38($s3)
/* B9E61C 80240CBC 8E66003C */  lw        $a2, 0x3c($s3)
/* B9E620 80240CC0 8E670040 */  lw        $a3, 0x40($s3)
/* B9E624 80240CC4 0C01BECC */  jal       fx_walk_normal
/* B9E628 80240CC8 24040002 */   addiu    $a0, $zero, 2
/* B9E62C 80240CCC 02E0202D */  daddu     $a0, $s7, $zero
/* B9E630 80240CD0 2402000C */  addiu     $v0, $zero, 0xc
/* B9E634 80240CD4 AE820070 */  sw        $v0, 0x70($s4)
/* B9E638 80240CD8 24020001 */  addiu     $v0, $zero, 1
/* B9E63C 80240CDC AFA20010 */  sw        $v0, 0x10($sp)
/* B9E640 80240CE0 8EC60024 */  lw        $a2, 0x24($s6)
/* B9E644 80240CE4 8EC70028 */  lw        $a3, 0x28($s6)
/* B9E648 80240CE8 0C01242D */  jal       func_800490B4
/* B9E64C 80240CEC 02A0282D */   daddu    $a1, $s5, $zero
/* B9E650 80240CF0 14400022 */  bnez      $v0, .L80240D7C
/* B9E654 80240CF4 24040002 */   addiu    $a0, $zero, 2
/* B9E658 80240CF8 0260282D */  daddu     $a1, $s3, $zero
/* B9E65C 80240CFC 0000302D */  daddu     $a2, $zero, $zero
/* B9E660 80240D00 866300A8 */  lh        $v1, 0xa8($s3)
/* B9E664 80240D04 3C013F80 */  lui       $at, 0x3f80
/* B9E668 80240D08 44810000 */  mtc1      $at, $f0
/* B9E66C 80240D0C 3C014000 */  lui       $at, 0x4000
/* B9E670 80240D10 44811000 */  mtc1      $at, $f2
/* B9E674 80240D14 3C01C1A0 */  lui       $at, 0xc1a0
/* B9E678 80240D18 44812000 */  mtc1      $at, $f4
/* B9E67C 80240D1C 2402000F */  addiu     $v0, $zero, 0xf
/* B9E680 80240D20 AFA2001C */  sw        $v0, 0x1c($sp)
/* B9E684 80240D24 44834000 */  mtc1      $v1, $f8
/* B9E688 80240D28 00000000 */  nop       
/* B9E68C 80240D2C 46804220 */  cvt.s.w   $f8, $f8
/* B9E690 80240D30 44074000 */  mfc1      $a3, $f8
/* B9E694 80240D34 27A2003C */  addiu     $v0, $sp, 0x3c
/* B9E698 80240D38 AFA20020 */  sw        $v0, 0x20($sp)
/* B9E69C 80240D3C E7A00010 */  swc1      $f0, 0x10($sp)
/* B9E6A0 80240D40 E7A20014 */  swc1      $f2, 0x14($sp)
/* B9E6A4 80240D44 0C01BFA4 */  jal       fx_emote
/* B9E6A8 80240D48 E7A40018 */   swc1     $f4, 0x18($sp)
/* B9E6AC 80240D4C 24020019 */  addiu     $v0, $zero, 0x19
/* B9E6B0 80240D50 A662008E */  sh        $v0, 0x8e($s3)
/* B9E6B4 80240D54 2402000E */  addiu     $v0, $zero, 0xe
/* B9E6B8 80240D58 0809035F */  j         .L80240D7C
/* B9E6BC 80240D5C AE820070 */   sw       $v0, 0x70($s4)
.L80240D60:
/* B9E6C0 80240D60 C664003C */  lwc1      $f4, 0x3c($s3)
/* B9E6C4 80240D64 C660001C */  lwc1      $f0, 0x1c($s3)
/* B9E6C8 80240D68 46002100 */  add.s     $f4, $f4, $f0
/* B9E6CC 80240D6C C6620014 */  lwc1      $f2, 0x14($s3)
/* B9E6D0 80240D70 46020001 */  sub.s     $f0, $f0, $f2
/* B9E6D4 80240D74 E664003C */  swc1      $f4, 0x3c($s3)
/* B9E6D8 80240D78 E660001C */  swc1      $f0, 0x1c($s3)
.L80240D7C:
/* B9E6DC 80240D7C 8FBF0060 */  lw        $ra, 0x60($sp)
/* B9E6E0 80240D80 8FB7005C */  lw        $s7, 0x5c($sp)
/* B9E6E4 80240D84 8FB60058 */  lw        $s6, 0x58($sp)
/* B9E6E8 80240D88 8FB50054 */  lw        $s5, 0x54($sp)
/* B9E6EC 80240D8C 8FB40050 */  lw        $s4, 0x50($sp)
/* B9E6F0 80240D90 8FB3004C */  lw        $s3, 0x4c($sp)
/* B9E6F4 80240D94 8FB20048 */  lw        $s2, 0x48($sp)
/* B9E6F8 80240D98 8FB10044 */  lw        $s1, 0x44($sp)
/* B9E6FC 80240D9C 8FB00040 */  lw        $s0, 0x40($sp)
/* B9E700 80240DA0 D7B40068 */  ldc1      $f20, 0x68($sp)
/* B9E704 80240DA4 03E00008 */  jr        $ra
/* B9E708 80240DA8 27BD0070 */   addiu    $sp, $sp, 0x70
