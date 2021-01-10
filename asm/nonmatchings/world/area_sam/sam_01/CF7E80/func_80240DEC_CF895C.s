.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DEC_CF895C
/* CF895C 80240DEC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF8960 80240DF0 AFB00010 */  sw        $s0, 0x10($sp)
/* CF8964 80240DF4 3C108011 */  lui       $s0, %hi(gPlayerData)
/* CF8968 80240DF8 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* CF896C 80240DFC AFBF0018 */  sw        $ra, 0x18($sp)
/* CF8970 80240E00 AFB10014 */  sw        $s1, 0x14($sp)
/* CF8974 80240E04 960302C0 */  lhu       $v1, 0x2c0($s0)
/* CF8978 80240E08 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* CF897C 80240E0C 10400003 */  beqz      $v0, .L80240E1C
/* CF8980 80240E10 0080882D */   daddu    $s1, $a0, $zero
/* CF8984 80240E14 24620001 */  addiu     $v0, $v1, 1
/* CF8988 80240E18 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80240E1C:
/* CF898C 80240E1C 3C05F5DE */  lui       $a1, 0xf5de
/* CF8990 80240E20 34A502E0 */  ori       $a1, $a1, 0x2e0
/* CF8994 80240E24 0C0B1EAF */  jal       get_variable
/* CF8998 80240E28 0000202D */   daddu    $a0, $zero, $zero
/* CF899C 80240E2C 3C038024 */  lui       $v1, %hi(func_802436FC_8B376C)
/* CF89A0 80240E30 00621821 */  addu      $v1, $v1, $v0
/* CF89A4 80240E34 906336FC */  lbu       $v1, %lo(func_802436FC_8B376C)($v1)
/* CF89A8 80240E38 8E220084 */  lw        $v0, 0x84($s1)
/* CF89AC 80240E3C 54430006 */  bnel      $v0, $v1, .L80240E58
/* CF89B0 80240E40 AE200084 */   sw       $zero, 0x84($s1)
/* CF89B4 80240E44 24020001 */  addiu     $v0, $zero, 1
/* CF89B8 80240E48 AE220084 */  sw        $v0, 0x84($s1)
/* CF89BC 80240E4C 960202C2 */  lhu       $v0, 0x2c2($s0)
/* CF89C0 80240E50 24420001 */  addiu     $v0, $v0, 1
/* CF89C4 80240E54 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80240E58:
/* CF89C8 80240E58 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF89CC 80240E5C 8FB10014 */  lw        $s1, 0x14($sp)
/* CF89D0 80240E60 8FB00010 */  lw        $s0, 0x10($sp)
/* CF89D4 80240E64 24020002 */  addiu     $v0, $zero, 2
/* CF89D8 80240E68 03E00008 */  jr        $ra
/* CF89DC 80240E6C 27BD0020 */   addiu    $sp, $sp, 0x20
