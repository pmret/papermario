.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_shadow_type
/* A8960 80112260 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A8964 80112264 0080182D */  daddu     $v1, $a0, $zero
/* A8968 80112268 AFB00010 */  sw        $s0, 0x10($sp)
/* A896C 8011226C 0000802D */  daddu     $s0, $zero, $zero
/* A8970 80112270 3C04802F */  lui       $a0, %hi(D_802E98BC)
/* A8974 80112274 248498BC */  addiu     $a0, $a0, %lo(D_802E98BC)
/* A8978 80112278 44850000 */  mtc1      $a1, $f0
/* A897C 8011227C 44861000 */  mtc1      $a2, $f2
/* A8980 80112280 44872000 */  mtc1      $a3, $f4
/* A8984 80112284 2C620006 */  sltiu     $v0, $v1, 6
/* A8988 80112288 AFBF0018 */  sw        $ra, 0x18($sp)
/* A898C 8011228C 10400014 */  beqz      $v0, .L801122E0
/* A8990 80112290 AFB10014 */   sw       $s1, 0x14($sp)
/* A8994 80112294 00031080 */  sll       $v0, $v1, 2
/* A8998 80112298 3C018015 */  lui       $at, %hi(jtbl_8014F928)
/* A899C 8011229C 00220821 */  addu      $at, $at, $v0
/* A89A0 801122A0 8C22F928 */  lw        $v0, %lo(jtbl_8014F928)($at)
/* A89A4 801122A4 00400008 */  jr        $v0
/* A89A8 801122A8 00000000 */   nop
glabel L801122AC_A89AC
/* A89AC 801122AC 24100001 */  addiu     $s0, $zero, 1
glabel L801122B0_A89B0
/* A89B0 801122B0 3C04802F */  lui       $a0, %hi(D_802E98BC)
/* A89B4 801122B4 248498BC */  addiu     $a0, $a0, %lo(D_802E98BC)
/* A89B8 801122B8 080448B8 */  j         .L801122E0
/* A89BC 801122BC 00000000 */   nop
glabel L801122C0_A89C0
/* A89C0 801122C0 24100001 */  addiu     $s0, $zero, 1
glabel L801122C4_A89C4
/* A89C4 801122C4 3C04802F */  lui       $a0, %hi(D_802E9904)
/* A89C8 801122C8 24849904 */  addiu     $a0, $a0, %lo(D_802E9904)
/* A89CC 801122CC 080448B8 */  j         .L801122E0
/* A89D0 801122D0 00000000 */   nop
glabel L801122D4_A89D4
/* A89D4 801122D4 24100001 */  addiu     $s0, $zero, 1
glabel L801122D8_A89D8
/* A89D8 801122D8 3C04802F */  lui       $a0, %hi(D_802E98E0)
/* A89DC 801122DC 248498E0 */  addiu     $a0, $a0, %lo(D_802E98E0)
.L801122E0:
/* A89E0 801122E0 44050000 */  mfc1      $a1, $f0
/* A89E4 801122E4 44061000 */  mfc1      $a2, $f2
/* A89E8 801122E8 44072000 */  mfc1      $a3, $f4
/* A89EC 801122EC 0C0446F6 */  jal       create_shadow_from_data
/* A89F0 801122F0 00000000 */   nop
/* A89F4 801122F4 12000006 */  beqz      $s0, .L80112310
/* A89F8 801122F8 0040882D */   daddu    $s1, $v0, $zero
/* A89FC 801122FC 0C044181 */  jal       get_shadow_by_index
/* A8A00 80112300 0220202D */   daddu    $a0, $s1, $zero
/* A8A04 80112304 8C430000 */  lw        $v1, ($v0)
/* A8A08 80112308 34630200 */  ori       $v1, $v1, 0x200
/* A8A0C 8011230C AC430000 */  sw        $v1, ($v0)
.L80112310:
/* A8A10 80112310 0220102D */  daddu     $v0, $s1, $zero
/* A8A14 80112314 8FBF0018 */  lw        $ra, 0x18($sp)
/* A8A18 80112318 8FB10014 */  lw        $s1, 0x14($sp)
/* A8A1C 8011231C 8FB00010 */  lw        $s0, 0x10($sp)
/* A8A20 80112320 03E00008 */  jr        $ra
/* A8A24 80112324 27BD0020 */   addiu    $sp, $sp, 0x20
