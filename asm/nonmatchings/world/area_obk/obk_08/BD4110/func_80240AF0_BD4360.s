.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AF0_BD4360
/* BD4360 80240AF0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD4364 80240AF4 AFB10014 */  sw        $s1, 0x14($sp)
/* BD4368 80240AF8 0080882D */  daddu     $s1, $a0, $zero
/* BD436C 80240AFC AFBF001C */  sw        $ra, 0x1c($sp)
/* BD4370 80240B00 AFB20018 */  sw        $s2, 0x18($sp)
/* BD4374 80240B04 AFB00010 */  sw        $s0, 0x10($sp)
/* BD4378 80240B08 0C00EABB */  jal       get_npc_unsafe
/* BD437C 80240B0C 8E24014C */   lw       $a0, 0x14c($s1)
/* BD4380 80240B10 0040802D */  daddu     $s0, $v0, $zero
/* BD4384 80240B14 8E230074 */  lw        $v1, 0x74($s1)
/* BD4388 80240B18 8E120020 */  lw        $s2, 0x20($s0)
/* BD438C 80240B1C 2C62000E */  sltiu     $v0, $v1, 0xe
/* BD4390 80240B20 10400058 */  beqz      $v0, .L80240C84
/* BD4394 80240B24 00031080 */   sll      $v0, $v1, 2
/* BD4398 80240B28 3C018024 */  lui       $at, %hi(D_80246EC8)
/* BD439C 80240B2C 00220821 */  addu      $at, $at, $v0
/* BD43A0 80240B30 8C226EC8 */  lw        $v0, %lo(D_80246EC8)($at)
/* BD43A4 80240B34 00400008 */  jr        $v0
/* BD43A8 80240B38 00000000 */   nop      
/* BD43AC 80240B3C 0220202D */  daddu     $a0, $s1, $zero
/* BD43B0 80240B40 3C05F971 */  lui       $a1, 0xf971
/* BD43B4 80240B44 0C0B1EAF */  jal       get_variable
/* BD43B8 80240B48 34A58888 */   ori      $a1, $a1, 0x8888
/* BD43BC 80240B4C 0040182D */  daddu     $v1, $v0, $zero
/* BD43C0 80240B50 24020001 */  addiu     $v0, $zero, 1
/* BD43C4 80240B54 1462004B */  bne       $v1, $v0, .L80240C84
/* BD43C8 80240B58 2402000A */   addiu    $v0, $zero, 0xa
/* BD43CC 80240B5C 08090320 */  j         .L80240C80
/* BD43D0 80240B60 AE430000 */   sw       $v1, ($s2)
/* BD43D4 80240B64 C600000C */  lwc1      $f0, 0xc($s0)
/* BD43D8 80240B68 3C014000 */  lui       $at, 0x4000
/* BD43DC 80240B6C 44816000 */  mtc1      $at, $f12
/* BD43E0 80240B70 0C00A6C9 */  jal       clamp_angle
/* BD43E4 80240B74 460C0300 */   add.s    $f12, $f0, $f12
/* BD43E8 80240B78 9602008E */  lhu       $v0, 0x8e($s0)
/* BD43EC 80240B7C E600000C */  swc1      $f0, 0xc($s0)
/* BD43F0 80240B80 2442FFFF */  addiu     $v0, $v0, -1
/* BD43F4 80240B84 A602008E */  sh        $v0, 0x8e($s0)
/* BD43F8 80240B88 00021400 */  sll       $v0, $v0, 0x10
/* BD43FC 80240B8C 1440003D */  bnez      $v0, .L80240C84
/* BD4400 80240B90 2402000B */   addiu    $v0, $zero, 0xb
/* BD4404 80240B94 08090321 */  j         .L80240C84
/* BD4408 80240B98 AE220074 */   sw       $v0, 0x74($s1)
/* BD440C 80240B9C C602003C */  lwc1      $f2, 0x3c($s0)
/* BD4410 80240BA0 3C01C466 */  lui       $at, 0xc466
/* BD4414 80240BA4 44810000 */  mtc1      $at, $f0
/* BD4418 80240BA8 00000000 */  nop       
/* BD441C 80240BAC 4600103E */  c.le.s    $f2, $f0
/* BD4420 80240BB0 00000000 */  nop       
/* BD4424 80240BB4 45000003 */  bc1f      .L80240BC4
/* BD4428 80240BB8 00000000 */   nop      
/* BD442C 80240BBC 0C09027A */  jal       func_802409E8_BD4258
/* BD4430 80240BC0 00000000 */   nop      
.L80240BC4:
/* BD4434 80240BC4 C600000C */  lwc1      $f0, 0xc($s0)
/* BD4438 80240BC8 3C014000 */  lui       $at, 0x4000
/* BD443C 80240BCC 44816000 */  mtc1      $at, $f12
/* BD4440 80240BD0 0C00A6C9 */  jal       clamp_angle
/* BD4444 80240BD4 460C0300 */   add.s    $f12, $f0, $f12
/* BD4448 80240BD8 C604003C */  lwc1      $f4, 0x3c($s0)
/* BD444C 80240BDC 3C013F00 */  lui       $at, 0x3f00
/* BD4450 80240BE0 44811000 */  mtc1      $at, $f2
/* BD4454 80240BE4 00000000 */  nop       
/* BD4458 80240BE8 46022101 */  sub.s     $f4, $f4, $f2
/* BD445C 80240BEC 3C01C477 */  lui       $at, 0xc477
/* BD4460 80240BF0 44811000 */  mtc1      $at, $f2
/* BD4464 80240BF4 E600000C */  swc1      $f0, 0xc($s0)
/* BD4468 80240BF8 4602203E */  c.le.s    $f4, $f2
/* BD446C 80240BFC 00000000 */  nop       
/* BD4470 80240C00 45000020 */  bc1f      .L80240C84
/* BD4474 80240C04 E604003C */   swc1     $f4, 0x3c($s0)
/* BD4478 80240C08 0220202D */  daddu     $a0, $s1, $zero
/* BD447C 80240C0C 3C05FD05 */  lui       $a1, 0xfd05
/* BD4480 80240C10 34A50F81 */  ori       $a1, $a1, 0xf81
/* BD4484 80240C14 0C0B2026 */  jal       set_variable
/* BD4488 80240C18 24060001 */   addiu    $a2, $zero, 1
/* BD448C 80240C1C 0C09029F */  jal       func_80240A7C_BD42EC
/* BD4490 80240C20 00000000 */   nop      
/* BD4494 80240C24 08090320 */  j         .L80240C80
/* BD4498 80240C28 2402000C */   addiu    $v0, $zero, 0xc
/* BD449C 80240C2C 0220202D */  daddu     $a0, $s1, $zero
/* BD44A0 80240C30 3C05FD05 */  lui       $a1, 0xfd05
/* BD44A4 80240C34 0C0B1EAF */  jal       get_variable
/* BD44A8 80240C38 34A50F82 */   ori      $a1, $a1, 0xf82
/* BD44AC 80240C3C 24030001 */  addiu     $v1, $zero, 1
/* BD44B0 80240C40 14430002 */  bne       $v0, $v1, .L80240C4C
/* BD44B4 80240C44 2402000D */   addiu    $v0, $zero, 0xd
/* BD44B8 80240C48 AE220074 */  sw        $v0, 0x74($s1)
.L80240C4C:
/* BD44BC 80240C4C C600000C */  lwc1      $f0, 0xc($s0)
/* BD44C0 80240C50 3C014000 */  lui       $at, 0x4000
/* BD44C4 80240C54 44816000 */  mtc1      $at, $f12
/* BD44C8 80240C58 0C00A6C9 */  jal       clamp_angle
/* BD44CC 80240C5C 460C0300 */   add.s    $f12, $f0, $f12
/* BD44D0 80240C60 08090321 */  j         .L80240C84
/* BD44D4 80240C64 E600000C */   swc1     $f0, 0xc($s0)
/* BD44D8 80240C68 0220202D */  daddu     $a0, $s1, $zero
/* BD44DC 80240C6C 3C05FD05 */  lui       $a1, 0xfd05
/* BD44E0 80240C70 0C0B1EAF */  jal       get_variable
/* BD44E4 80240C74 34A50F82 */   ori      $a1, $a1, 0xf82
/* BD44E8 80240C78 14400002 */  bnez      $v0, .L80240C84
/* BD44EC 80240C7C 2402000C */   addiu    $v0, $zero, 0xc
.L80240C80:
/* BD44F0 80240C80 AE220074 */  sw        $v0, 0x74($s1)
.L80240C84:
/* BD44F4 80240C84 8FBF001C */  lw        $ra, 0x1c($sp)
/* BD44F8 80240C88 8FB20018 */  lw        $s2, 0x18($sp)
/* BD44FC 80240C8C 8FB10014 */  lw        $s1, 0x14($sp)
/* BD4500 80240C90 8FB00010 */  lw        $s0, 0x10($sp)
/* BD4504 80240C94 24020002 */  addiu     $v0, $zero, 2
/* BD4508 80240C98 03E00008 */  jr        $ra
/* BD450C 80240C9C 27BD0020 */   addiu    $sp, $sp, 0x20
