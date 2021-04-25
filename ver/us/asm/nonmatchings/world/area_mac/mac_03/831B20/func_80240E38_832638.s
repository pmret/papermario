.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E38_832638
/* 832638 80240E38 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 83263C 80240E3C 10A0000B */  beqz      $a1, .L80240E6C
/* 832640 80240E40 AFBF0010 */   sw       $ra, 0x10($sp)
/* 832644 80240E44 3C038025 */  lui       $v1, %hi(D_802513F4)
/* 832648 80240E48 8C6313F4 */  lw        $v1, %lo(D_802513F4)($v1)
/* 83264C 80240E4C 8C620000 */  lw        $v0, ($v1)
/* 832650 80240E50 3C048025 */  lui       $a0, %hi(D_802513F8)
/* 832654 80240E54 8C8413F8 */  lw        $a0, %lo(D_802513F8)($a0)
/* 832658 80240E58 34420010 */  ori       $v0, $v0, 0x10
/* 83265C 80240E5C AC620000 */  sw        $v0, ($v1)
/* 832660 80240E60 8C820000 */  lw        $v0, ($a0)
/* 832664 80240E64 34420010 */  ori       $v0, $v0, 0x10
/* 832668 80240E68 AC820000 */  sw        $v0, ($a0)
.L80240E6C:
/* 83266C 80240E6C 3C048025 */  lui       $a0, %hi(ForceCloseMessageBox)
/* 832670 80240E70 8C8413F0 */  lw        $a0, %lo(ForceCloseMessageBox)($a0)
/* 832674 80240E74 8C85000C */  lw        $a1, 0xc($a0)
/* 832678 80240E78 8CA20018 */  lw        $v0, 0x18($a1)
/* 83267C 80240E7C 8CA30020 */  lw        $v1, 0x20($a1)
/* 832680 80240E80 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 832684 80240E84 ACA20018 */  sw        $v0, 0x18($a1)
/* 832688 80240E88 8CA20024 */  lw        $v0, 0x24($a1)
/* 83268C 80240E8C 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 832690 80240E90 ACA30020 */  sw        $v1, 0x20($a1)
/* 832694 80240E94 8CA30028 */  lw        $v1, 0x28($a1)
/* 832698 80240E98 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 83269C 80240E9C ACA20024 */  sw        $v0, 0x24($a1)
/* 8326A0 80240EA0 8CA2001C */  lw        $v0, 0x1c($a1)
/* 8326A4 80240EA4 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 8326A8 80240EA8 ACA30028 */  sw        $v1, 0x28($a1)
/* 8326AC 80240EAC 8CA30018 */  lw        $v1, 0x18($a1)
/* 8326B0 80240EB0 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 8326B4 80240EB4 18600003 */  blez      $v1, .L80240EC4
/* 8326B8 80240EB8 ACA2001C */   sw       $v0, 0x1c($a1)
/* 8326BC 80240EBC 080903B8 */  j         .L80240EE0
/* 8326C0 80240EC0 0000102D */   daddu    $v0, $zero, $zero
.L80240EC4:
/* 8326C4 80240EC4 0C016914 */  jal       remove_effect
/* 8326C8 80240EC8 ACA00018 */   sw       $zero, 0x18($a1)
/* 8326CC 80240ECC 3C048025 */  lui       $a0, %hi(D_802513D0)
/* 8326D0 80240ED0 8C8413D0 */  lw        $a0, %lo(D_802513D0)($a0)
/* 8326D4 80240ED4 0C048D70 */  jal       free_dynamic_entity
/* 8326D8 80240ED8 00000000 */   nop
/* 8326DC 80240EDC 24020002 */  addiu     $v0, $zero, 2
.L80240EE0:
/* 8326E0 80240EE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8326E4 80240EE4 03E00008 */  jr        $ra
/* 8326E8 80240EE8 27BD0018 */   addiu    $sp, $sp, 0x18
