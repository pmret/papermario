.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024244C_A95B8C
/* A95B8C 8024244C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A95B90 80242450 AFB40040 */  sw        $s4, 0x40($sp)
/* A95B94 80242454 0080A02D */  daddu     $s4, $a0, $zero
/* A95B98 80242458 AFBF0044 */  sw        $ra, 0x44($sp)
/* A95B9C 8024245C AFB3003C */  sw        $s3, 0x3c($sp)
/* A95BA0 80242460 AFB20038 */  sw        $s2, 0x38($sp)
/* A95BA4 80242464 AFB10034 */  sw        $s1, 0x34($sp)
/* A95BA8 80242468 AFB00030 */  sw        $s0, 0x30($sp)
/* A95BAC 8024246C F7B40048 */  sdc1      $f20, 0x48($sp)
/* A95BB0 80242470 8E900148 */  lw        $s0, 0x148($s4)
/* A95BB4 80242474 00A0882D */  daddu     $s1, $a1, $zero
/* A95BB8 80242478 86040008 */  lh        $a0, 8($s0)
/* A95BBC 8024247C 0C00EABB */  jal       get_npc_unsafe
/* A95BC0 80242480 00C0902D */   daddu    $s2, $a2, $zero
/* A95BC4 80242484 C60C006C */  lwc1      $f12, 0x6c($s0)
/* A95BC8 80242488 46806320 */  cvt.s.w   $f12, $f12
/* A95BCC 8024248C 0040982D */  daddu     $s3, $v0, $zero
/* A95BD0 80242490 C6140070 */  lwc1      $f20, 0x70($s0)
/* A95BD4 80242494 4680A520 */  cvt.s.w   $f20, $f20
/* A95BD8 80242498 3C014059 */  lui       $at, 0x4059
/* A95BDC 8024249C 44810800 */  mtc1      $at, $f1
/* A95BE0 802424A0 44800000 */  mtc1      $zero, $f0
/* A95BE4 802424A4 4600A521 */  cvt.d.s   $f20, $f20
/* A95BE8 802424A8 4620A503 */  div.d     $f20, $f20, $f0
/* A95BEC 802424AC 0C00A8BB */  jal       sin_deg
/* A95BF0 802424B0 4620A520 */   cvt.s.d  $f20, $f20
/* A95BF4 802424B4 3C014018 */  lui       $at, 0x4018
/* A95BF8 802424B8 44811800 */  mtc1      $at, $f3
/* A95BFC 802424BC 44801000 */  mtc1      $zero, $f2
/* A95C00 802424C0 46000021 */  cvt.d.s   $f0, $f0
/* A95C04 802424C4 46220002 */  mul.d     $f0, $f0, $f2
/* A95C08 802424C8 00000000 */  nop       
/* A95C0C 802424CC 4600A0A1 */  cvt.d.s   $f2, $f20
/* A95C10 802424D0 46201080 */  add.d     $f2, $f2, $f0
/* A95C14 802424D4 462010A0 */  cvt.s.d   $f2, $f2
/* A95C18 802424D8 E662003C */  swc1      $f2, 0x3c($s3)
/* A95C1C 802424DC 8E02006C */  lw        $v0, 0x6c($s0)
/* A95C20 802424E0 2442000A */  addiu     $v0, $v0, 0xa
/* A95C24 802424E4 44826000 */  mtc1      $v0, $f12
/* A95C28 802424E8 00000000 */  nop       
/* A95C2C 802424EC 0C00A6C9 */  jal       clamp_angle
/* A95C30 802424F0 46806320 */   cvt.s.w  $f12, $f12
/* A95C34 802424F4 4600018D */  trunc.w.s $f6, $f0
/* A95C38 802424F8 E606006C */  swc1      $f6, 0x6c($s0)
/* A95C3C 802424FC 0280202D */  daddu     $a0, $s4, $zero
/* A95C40 80242500 8E250024 */  lw        $a1, 0x24($s1)
/* A95C44 80242504 8E260028 */  lw        $a2, 0x28($s1)
/* A95C48 80242508 0C09074C */  jal       func_80241D30_A95470
/* A95C4C 8024250C 0240382D */   daddu    $a3, $s2, $zero
/* A95C50 80242510 24030001 */  addiu     $v1, $zero, 1
/* A95C54 80242514 1443001E */  bne       $v0, $v1, .L80242590
/* A95C58 80242518 0000202D */   daddu    $a0, $zero, $zero
/* A95C5C 8024251C 0260282D */  daddu     $a1, $s3, $zero
/* A95C60 80242520 0000302D */  daddu     $a2, $zero, $zero
/* A95C64 80242524 866300A8 */  lh        $v1, 0xa8($s3)
/* A95C68 80242528 3C013F80 */  lui       $at, 0x3f80
/* A95C6C 8024252C 44810000 */  mtc1      $at, $f0
/* A95C70 80242530 3C014000 */  lui       $at, 0x4000
/* A95C74 80242534 44811000 */  mtc1      $at, $f2
/* A95C78 80242538 3C01C1A0 */  lui       $at, 0xc1a0
/* A95C7C 8024253C 44812000 */  mtc1      $at, $f4
/* A95C80 80242540 2402000F */  addiu     $v0, $zero, 0xf
/* A95C84 80242544 AFA2001C */  sw        $v0, 0x1c($sp)
/* A95C88 80242548 44833000 */  mtc1      $v1, $f6
/* A95C8C 8024254C 00000000 */  nop       
/* A95C90 80242550 468031A0 */  cvt.s.w   $f6, $f6
/* A95C94 80242554 44073000 */  mfc1      $a3, $f6
/* A95C98 80242558 27A20028 */  addiu     $v0, $sp, 0x28
/* A95C9C 8024255C AFA20020 */  sw        $v0, 0x20($sp)
/* A95CA0 80242560 E7A00010 */  swc1      $f0, 0x10($sp)
/* A95CA4 80242564 E7A20014 */  swc1      $f2, 0x14($sp)
/* A95CA8 80242568 0C01BFA4 */  jal       fx_emote
/* A95CAC 8024256C E7A40018 */   swc1     $f4, 0x18($sp)
/* A95CB0 80242570 0260202D */  daddu     $a0, $s3, $zero
/* A95CB4 80242574 240502F4 */  addiu     $a1, $zero, 0x2f4
/* A95CB8 80242578 0C012530 */  jal       func_800494C0
/* A95CBC 8024257C 3C060020 */   lui      $a2, 0x20
/* A95CC0 80242580 24020032 */  addiu     $v0, $zero, 0x32
/* A95CC4 80242584 A662008E */  sh        $v0, 0x8e($s3)
/* A95CC8 80242588 0809096C */  j         .L802425B0
/* A95CCC 8024258C 24020014 */   addiu    $v0, $zero, 0x14
.L80242590:
/* A95CD0 80242590 9662008E */  lhu       $v0, 0x8e($s3)
/* A95CD4 80242594 2442FFFF */  addiu     $v0, $v0, -1
/* A95CD8 80242598 A662008E */  sh        $v0, 0x8e($s3)
/* A95CDC 8024259C 00021400 */  sll       $v0, $v0, 0x10
/* A95CE0 802425A0 1C400004 */  bgtz      $v0, .L802425B4
/* A95CE4 802425A4 24020005 */   addiu    $v0, $zero, 5
/* A95CE8 802425A8 A662008E */  sh        $v0, 0x8e($s3)
/* A95CEC 802425AC 2402000F */  addiu     $v0, $zero, 0xf
.L802425B0:
/* A95CF0 802425B0 AE820070 */  sw        $v0, 0x70($s4)
.L802425B4:
/* A95CF4 802425B4 8FBF0044 */  lw        $ra, 0x44($sp)
/* A95CF8 802425B8 8FB40040 */  lw        $s4, 0x40($sp)
/* A95CFC 802425BC 8FB3003C */  lw        $s3, 0x3c($sp)
/* A95D00 802425C0 8FB20038 */  lw        $s2, 0x38($sp)
/* A95D04 802425C4 8FB10034 */  lw        $s1, 0x34($sp)
/* A95D08 802425C8 8FB00030 */  lw        $s0, 0x30($sp)
/* A95D0C 802425CC D7B40048 */  ldc1      $f20, 0x48($sp)
/* A95D10 802425D0 03E00008 */  jr        $ra
/* A95D14 802425D4 27BD0050 */   addiu    $sp, $sp, 0x50
