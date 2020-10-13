.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel start_script
/* E7D90 802C33E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E7D94 802C33E4 AFB10014 */  sw        $s1, 0x14($sp)
/* E7D98 802C33E8 0080882D */  daddu     $s1, $a0, $zero
/* E7D9C 802C33EC AFB40020 */  sw        $s4, 0x20($sp)
/* E7DA0 802C33F0 00A0A02D */  daddu     $s4, $a1, $zero
/* E7DA4 802C33F4 AFB3001C */  sw        $s3, 0x1c($sp)
/* E7DA8 802C33F8 00C0982D */  daddu     $s3, $a2, $zero
/* E7DAC 802C33FC 3C03802E */  lui       $v1, %hi(gCurrentScriptListPtr)
/* E7DB0 802C3400 8C63A890 */  lw        $v1, %lo(gCurrentScriptListPtr)($v1)
/* E7DB4 802C3404 0000282D */  daddu     $a1, $zero, $zero
/* E7DB8 802C3408 AFBF0024 */  sw        $ra, 0x24($sp)
/* E7DBC 802C340C AFB20018 */  sw        $s2, 0x18($sp)
/* E7DC0 802C3410 AFB00010 */  sw        $s0, 0x10($sp)
.L802C3414:
/* E7DC4 802C3414 8C620000 */  lw        $v0, ($v1)
/* E7DC8 802C3418 10400006 */  beqz      $v0, .L802C3434
/* E7DCC 802C341C 28A20080 */   slti     $v0, $a1, 0x80
/* E7DD0 802C3420 24A50001 */  addiu     $a1, $a1, 1
/* E7DD4 802C3424 28A20080 */  slti      $v0, $a1, 0x80
/* E7DD8 802C3428 1440FFFA */  bnez      $v0, .L802C3414
/* E7DDC 802C342C 24630004 */   addiu    $v1, $v1, 4
/* E7DE0 802C3430 28A20080 */  slti      $v0, $a1, 0x80
.L802C3434:
/* E7DE4 802C3434 14400003 */  bnez      $v0, .L802C3444
/* E7DE8 802C3438 24040168 */   addiu    $a0, $zero, 0x168
.L802C343C:
/* E7DEC 802C343C 080B0D0F */  j         .L802C343C
/* E7DF0 802C3440 00000000 */   nop      
.L802C3444:
/* E7DF4 802C3444 0C00AB39 */  jal       heap_malloc
/* E7DF8 802C3448 00A0902D */   daddu    $s2, $a1, $zero
/* E7DFC 802C344C 00122080 */  sll       $a0, $s2, 2
/* E7E00 802C3450 3C03802E */  lui       $v1, %hi(gCurrentScriptListPtr)
/* E7E04 802C3454 8C63A890 */  lw        $v1, %lo(gCurrentScriptListPtr)($v1)
/* E7E08 802C3458 3C05802E */  lui       $a1, %hi(gNumScripts)
/* E7E0C 802C345C 24A5A488 */  addiu     $a1, $a1, %lo(gNumScripts)
/* E7E10 802C3460 00832021 */  addu      $a0, $a0, $v1
/* E7E14 802C3464 8CA30000 */  lw        $v1, ($a1)
/* E7E18 802C3468 0040802D */  daddu     $s0, $v0, $zero
/* E7E1C 802C346C AC900000 */  sw        $s0, ($a0)
/* E7E20 802C3470 24630001 */  addiu     $v1, $v1, 1
/* E7E24 802C3474 16000003 */  bnez      $s0, .L802C3484
/* E7E28 802C3478 ACA30000 */   sw       $v1, ($a1)
.L802C347C:
/* E7E2C 802C347C 080B0D1F */  j         .L802C347C
/* E7E30 802C3480 00000000 */   nop      
.L802C3484:
/* E7E34 802C3484 36620001 */  ori       $v0, $s3, 1
/* E7E38 802C3488 3C03802E */  lui       $v1, 0x802e
/* E7E3C 802C348C 24639CA0 */  addiu     $v1, $v1, -0x6360
/* E7E40 802C3490 A2020000 */  sb        $v0, ($s0)
/* E7E44 802C3494 A2000002 */  sb        $zero, 2($s0)
/* E7E48 802C3498 A2140003 */  sb        $s4, 3($s0)
/* E7E4C 802C349C 8C620000 */  lw        $v0, ($v1)
/* E7E50 802C34A0 2405000F */  addiu     $a1, $zero, 0xf
/* E7E54 802C34A4 AE020144 */  sw        $v0, 0x144($s0)
/* E7E58 802C34A8 24420001 */  addiu     $v0, $v0, 1
/* E7E5C 802C34AC AC620000 */  sw        $v0, ($v1)
/* E7E60 802C34B0 2403FFFF */  addiu     $v1, $zero, -1
/* E7E64 802C34B4 240200EF */  addiu     $v0, $zero, 0xef
/* E7E68 802C34B8 A2030006 */  sb        $v1, 6($s0)
/* E7E6C 802C34BC A2030007 */  sb        $v1, 7($s0)
/* E7E70 802C34C0 A2020004 */  sb        $v0, 4($s0)
/* E7E74 802C34C4 3C01802E */  lui       $at, 0x802e
/* E7E78 802C34C8 C4209CA8 */  lwc1      $f0, -0x6358($at)
/* E7E7C 802C34CC 2602003C */  addiu     $v0, $s0, 0x3c
/* E7E80 802C34D0 AE110008 */  sw        $s1, 8($s0)
/* E7E84 802C34D4 AE11015C */  sw        $s1, 0x15c($s0)
/* E7E88 802C34D8 AE110164 */  sw        $s1, 0x164($s0)
/* E7E8C 802C34DC AE000060 */  sw        $zero, 0x60($s0)
/* E7E90 802C34E0 AE000064 */  sw        $zero, 0x64($s0)
/* E7E94 802C34E4 AE000068 */  sw        $zero, 0x68($s0)
/* E7E98 802C34E8 AE00006C */  sw        $zero, 0x6c($s0)
/* E7E9C 802C34EC AE030148 */  sw        $v1, 0x148($s0)
/* E7EA0 802C34F0 AE03014C */  sw        $v1, 0x14c($s0)
/* E7EA4 802C34F4 AE000160 */  sw        $zero, 0x160($s0)
/* E7EA8 802C34F8 AE000154 */  sw        $zero, 0x154($s0)
/* E7EAC 802C34FC AE000158 */  sw        $zero, 0x158($s0)
/* E7EB0 802C3500 E6000150 */  swc1      $f0, 0x150($s0)
.L802C3504:
/* E7EB4 802C3504 AC400084 */  sw        $zero, 0x84($v0)
/* E7EB8 802C3508 24A5FFFF */  addiu     $a1, $a1, -1
/* E7EBC 802C350C 04A1FFFD */  bgez      $a1, .L802C3504
/* E7EC0 802C3510 2442FFFC */   addiu    $v0, $v0, -4
/* E7EC4 802C3514 24050002 */  addiu     $a1, $zero, 2
/* E7EC8 802C3518 26020008 */  addiu     $v0, $s0, 8
.L802C351C:
/* E7ECC 802C351C AC4000C4 */  sw        $zero, 0xc4($v0)
/* E7ED0 802C3520 24A5FFFF */  addiu     $a1, $a1, -1
/* E7ED4 802C3524 04A1FFFD */  bgez      $a1, .L802C351C
/* E7ED8 802C3528 2442FFFC */   addiu    $v0, $v0, -4
/* E7EDC 802C352C 0C0B0C52 */  jal       find_script_labels
/* E7EE0 802C3530 0200202D */   daddu    $a0, $s0, $zero
/* E7EE4 802C3534 3C02802E */  lui       $v0, %hi(D_802D9CA4)
/* E7EE8 802C3538 8C429CA4 */  lw        $v0, %lo(D_802D9CA4)($v0)
/* E7EEC 802C353C 10400012 */  beqz      $v0, .L802C3588
/* E7EF0 802C3540 00000000 */   nop      
/* E7EF4 802C3544 92020000 */  lbu       $v0, ($s0)
/* E7EF8 802C3548 30420020 */  andi      $v0, $v0, 0x20
/* E7EFC 802C354C 1040000E */  beqz      $v0, .L802C3588
/* E7F00 802C3550 00000000 */   nop      
/* E7F04 802C3554 3C05802E */  lui       $a1, %hi(gScriptListCount)
/* E7F08 802C3558 24A5AC98 */  addiu     $a1, $a1, %lo(gScriptListCount)
/* E7F0C 802C355C 8CA20000 */  lw        $v0, ($a1)
/* E7F10 802C3560 00022080 */  sll       $a0, $v0, 2
/* E7F14 802C3564 3C01802E */  lui       $at, 0x802e
/* E7F18 802C3568 00240821 */  addu      $at, $at, $a0
/* E7F1C 802C356C AC32A898 */  sw        $s2, -0x5768($at)
/* E7F20 802C3570 8E030144 */  lw        $v1, 0x144($s0)
/* E7F24 802C3574 24420001 */  addiu     $v0, $v0, 1
/* E7F28 802C3578 ACA20000 */  sw        $v0, ($a1)
/* E7F2C 802C357C 3C01802E */  lui       $at, %hi(gScriptIdList)
/* E7F30 802C3580 00240821 */  addu      $at, $at, $a0
/* E7F34 802C3584 AC23AA98 */  sw        $v1, %lo(gScriptIdList)($at)
.L802C3588:
/* E7F38 802C3588 0C0B0CE4 */  jal       func_802C3390
/* E7F3C 802C358C 0200202D */   daddu    $a0, $s0, $zero
/* E7F40 802C3590 3C03802E */  lui       $v1, 0x802e
/* E7F44 802C3594 24639CA0 */  addiu     $v1, $v1, -0x6360
/* E7F48 802C3598 8C620000 */  lw        $v0, ($v1)
/* E7F4C 802C359C 14400004 */  bnez      $v0, .L802C35B0
/* E7F50 802C35A0 0200102D */   daddu    $v0, $s0, $zero
/* E7F54 802C35A4 24020001 */  addiu     $v0, $zero, 1
/* E7F58 802C35A8 AC620000 */  sw        $v0, ($v1)
/* E7F5C 802C35AC 0200102D */  daddu     $v0, $s0, $zero
.L802C35B0:
/* E7F60 802C35B0 8FBF0024 */  lw        $ra, 0x24($sp)
/* E7F64 802C35B4 8FB40020 */  lw        $s4, 0x20($sp)
/* E7F68 802C35B8 8FB3001C */  lw        $s3, 0x1c($sp)
/* E7F6C 802C35BC 8FB20018 */  lw        $s2, 0x18($sp)
/* E7F70 802C35C0 8FB10014 */  lw        $s1, 0x14($sp)
/* E7F74 802C35C4 8FB00010 */  lw        $s0, 0x10($sp)
/* E7F78 802C35C8 03E00008 */  jr        $ra
/* E7F7C 802C35CC 27BD0028 */   addiu    $sp, $sp, 0x28
