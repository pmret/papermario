.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050CA0
/* 2C0A0 80050CA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2C0A4 80050CA4 0080302D */  daddu     $a2, $a0, $zero
/* 2C0A8 80050CA8 AFB20018 */  sw        $s2, 0x18($sp)
/* 2C0AC 80050CAC 00A0902D */  daddu     $s2, $a1, $zero
/* 2C0B0 80050CB0 AFB10014 */  sw        $s1, 0x14($sp)
/* 2C0B4 80050CB4 0000882D */  daddu     $s1, $zero, $zero
/* 2C0B8 80050CB8 00061900 */  sll       $v1, $a2, 4
/* 2C0BC 80050CBC 00661823 */  subu      $v1, $v1, $a2
/* 2C0C0 80050CC0 000318C0 */  sll       $v1, $v1, 3
/* 2C0C4 80050CC4 00661821 */  addu      $v1, $v1, $a2
/* 2C0C8 80050CC8 00031880 */  sll       $v1, $v1, 2
/* 2C0CC 80050CCC 24630024 */  addiu     $v1, $v1, 0x24
/* 2C0D0 80050CD0 3C04800A */  lui       $a0, %hi(D_8009A628)
/* 2C0D4 80050CD4 8C84A628 */  lw        $a0, %lo(D_8009A628)($a0)
/* 2C0D8 80050CD8 00061080 */  sll       $v0, $a2, 2
/* 2C0DC 80050CDC AFBF001C */  sw        $ra, 0x1c($sp)
/* 2C0E0 80050CE0 AFB00010 */  sw        $s0, 0x10($sp)
/* 2C0E4 80050CE4 00821021 */  addu      $v0, $a0, $v0
/* 2C0E8 80050CE8 8C450010 */  lw        $a1, 0x10($v0)
/* 2C0EC 80050CEC 10A00010 */  beqz      $a1, .L80050D30
/* 2C0F0 80050CF0 00838021 */   addu     $s0, $a0, $v1
/* 2C0F4 80050CF4 8E020020 */  lw        $v0, 0x20($s0)
/* 2C0F8 80050CF8 5440000E */  bnel      $v0, $zero, .L80050D34
/* 2C0FC 80050CFC 24110001 */   addiu    $s1, $zero, 1
/* 2C100 80050D00 0C014429 */  jal       func_800510A4
/* 2C104 80050D04 00000000 */   nop      
/* 2C108 80050D08 1240000A */  beqz      $s2, .L80050D34
/* 2C10C 80050D0C 0200202D */   daddu    $a0, $s0, $zero
/* 2C110 80050D10 2402007F */  addiu     $v0, $zero, 0x7f
/* 2C114 80050D14 A4920028 */  sh        $s2, 0x28($a0)
/* 2C118 80050D18 A080002A */  sb        $zero, 0x2a($a0)
/* 2C11C 80050D1C A082002B */  sb        $v0, 0x2b($a0)
/* 2C120 80050D20 0C014354 */  jal       func_80050D50
/* 2C124 80050D24 A0800026 */   sb       $zero, 0x26($a0)
/* 2C128 80050D28 0801434E */  j         .L80050D38
/* 2C12C 80050D2C 0220102D */   daddu    $v0, $s1, $zero
.L80050D30:
/* 2C130 80050D30 24110002 */  addiu     $s1, $zero, 2
.L80050D34:
/* 2C134 80050D34 0220102D */  daddu     $v0, $s1, $zero
.L80050D38:
/* 2C138 80050D38 8FBF001C */  lw        $ra, 0x1c($sp)
/* 2C13C 80050D3C 8FB20018 */  lw        $s2, 0x18($sp)
/* 2C140 80050D40 8FB10014 */  lw        $s1, 0x14($sp)
/* 2C144 80050D44 8FB00010 */  lw        $s0, 0x10($sp)
/* 2C148 80050D48 03E00008 */  jr        $ra
/* 2C14C 80050D4C 27BD0020 */   addiu    $sp, $sp, 0x20
