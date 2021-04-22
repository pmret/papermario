.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050950
/* 2BD50 80050950 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2BD54 80050954 0080302D */  daddu     $a2, $a0, $zero
/* 2BD58 80050958 AFB20018 */  sw        $s2, 0x18($sp)
/* 2BD5C 8005095C 00A0902D */  daddu     $s2, $a1, $zero
/* 2BD60 80050960 AFB10014 */  sw        $s1, 0x14($sp)
/* 2BD64 80050964 0000882D */  daddu     $s1, $zero, $zero
/* 2BD68 80050968 00061900 */  sll       $v1, $a2, 4
/* 2BD6C 8005096C 00661823 */  subu      $v1, $v1, $a2
/* 2BD70 80050970 000318C0 */  sll       $v1, $v1, 3
/* 2BD74 80050974 00661821 */  addu      $v1, $v1, $a2
/* 2BD78 80050978 00031880 */  sll       $v1, $v1, 2
/* 2BD7C 8005097C 24630024 */  addiu     $v1, $v1, 0x24
/* 2BD80 80050980 3C04800A */  lui       $a0, %hi(D_8009A608)
/* 2BD84 80050984 8C84A608 */  lw        $a0, %lo(D_8009A608)($a0)
/* 2BD88 80050988 00061080 */  sll       $v0, $a2, 2
/* 2BD8C 8005098C AFBF001C */  sw        $ra, 0x1c($sp)
/* 2BD90 80050990 AFB00010 */  sw        $s0, 0x10($sp)
/* 2BD94 80050994 00821021 */  addu      $v0, $a0, $v0
/* 2BD98 80050998 8C450010 */  lw        $a1, 0x10($v0)
/* 2BD9C 8005099C 10A00010 */  beqz      $a1, .L800509E0
/* 2BDA0 800509A0 00838021 */   addu     $s0, $a0, $v1
/* 2BDA4 800509A4 8E020020 */  lw        $v0, 0x20($s0)
/* 2BDA8 800509A8 5440000E */  bnel      $v0, $zero, .L800509E4
/* 2BDAC 800509AC 24110001 */   addiu    $s1, $zero, 1
/* 2BDB0 800509B0 0C014355 */  jal       func_80050D54
/* 2BDB4 800509B4 00000000 */   nop
/* 2BDB8 800509B8 1240000A */  beqz      $s2, .L800509E4
/* 2BDBC 800509BC 0200202D */   daddu    $a0, $s0, $zero
/* 2BDC0 800509C0 2402007F */  addiu     $v0, $zero, 0x7f
/* 2BDC4 800509C4 A4920028 */  sh        $s2, 0x28($a0)
/* 2BDC8 800509C8 A080002A */  sb        $zero, 0x2a($a0)
/* 2BDCC 800509CC A082002B */  sb        $v0, 0x2b($a0)
/* 2BDD0 800509D0 0C014280 */  jal       func_80050A00
/* 2BDD4 800509D4 A0800026 */   sb       $zero, 0x26($a0)
/* 2BDD8 800509D8 0801427A */  j         .L800509E8
/* 2BDDC 800509DC 0220102D */   daddu    $v0, $s1, $zero
.L800509E0:
/* 2BDE0 800509E0 24110002 */  addiu     $s1, $zero, 2
.L800509E4:
/* 2BDE4 800509E4 0220102D */  daddu     $v0, $s1, $zero
.L800509E8:
/* 2BDE8 800509E8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 2BDEC 800509EC 8FB20018 */  lw        $s2, 0x18($sp)
/* 2BDF0 800509F0 8FB10014 */  lw        $s1, 0x14($sp)
/* 2BDF4 800509F4 8FB00010 */  lw        $s0, 0x10($sp)
/* 2BDF8 800509F8 03E00008 */  jr        $ra
/* 2BDFC 800509FC 27BD0020 */   addiu    $sp, $sp, 0x20
