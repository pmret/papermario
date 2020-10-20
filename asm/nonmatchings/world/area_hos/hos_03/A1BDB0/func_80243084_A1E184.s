.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243084_A1E184
/* A1E184 80243084 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A1E188 80243088 AFB10014 */  sw        $s1, 0x14($sp)
/* A1E18C 8024308C 0080882D */  daddu     $s1, $a0, $zero
/* A1E190 80243090 AFBF0018 */  sw        $ra, 0x18($sp)
/* A1E194 80243094 AFB00010 */  sw        $s0, 0x10($sp)
/* A1E198 80243098 8E30000C */  lw        $s0, 0xc($s1)
/* A1E19C 8024309C 8E050000 */  lw        $a1, ($s0)
/* A1E1A0 802430A0 0C0B1EAF */  jal       get_variable
/* A1E1A4 802430A4 26100004 */   addiu    $s0, $s0, 4
/* A1E1A8 802430A8 00021880 */  sll       $v1, $v0, 2
/* A1E1AC 802430AC 00621821 */  addu      $v1, $v1, $v0
/* A1E1B0 802430B0 00031880 */  sll       $v1, $v1, 2
/* A1E1B4 802430B4 00621823 */  subu      $v1, $v1, $v0
/* A1E1B8 802430B8 000310C0 */  sll       $v0, $v1, 3
/* A1E1BC 802430BC 00621821 */  addu      $v1, $v1, $v0
/* A1E1C0 802430C0 000318C0 */  sll       $v1, $v1, 3
/* A1E1C4 802430C4 3C01800B */  lui       $at, 0x800b
/* A1E1C8 802430C8 00230821 */  addu      $at, $at, $v1
/* A1E1CC 802430CC C4221D98 */  lwc1      $f2, 0x1d98($at)
/* A1E1D0 802430D0 3C014480 */  lui       $at, 0x4480
/* A1E1D4 802430D4 44810000 */  mtc1      $at, $f0
/* A1E1D8 802430D8 00000000 */  nop       
/* A1E1DC 802430DC 46001082 */  mul.s     $f2, $f2, $f0
/* A1E1E0 802430E0 00000000 */  nop       
/* A1E1E4 802430E4 3C01CD5B */  lui       $at, 0xcd5b
/* A1E1E8 802430E8 34215858 */  ori       $at, $at, 0x5858
/* A1E1EC 802430EC 44810000 */  mtc1      $at, $f0
/* A1E1F0 802430F0 00000000 */  nop       
/* A1E1F4 802430F4 46001080 */  add.s     $f2, $f2, $f0
/* A1E1F8 802430F8 8E050000 */  lw        $a1, ($s0)
/* A1E1FC 802430FC 4600110D */  trunc.w.s $f4, $f2
/* A1E200 80243100 44062000 */  mfc1      $a2, $f4
/* A1E204 80243104 0C0B2026 */  jal       set_variable
/* A1E208 80243108 0220202D */   daddu    $a0, $s1, $zero
/* A1E20C 8024310C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A1E210 80243110 8FB10014 */  lw        $s1, 0x14($sp)
/* A1E214 80243114 8FB00010 */  lw        $s0, 0x10($sp)
/* A1E218 80243118 24020002 */  addiu     $v0, $zero, 2
/* A1E21C 8024311C 03E00008 */  jr        $ra
/* A1E220 80243120 27BD0020 */   addiu    $sp, $sp, 0x20
