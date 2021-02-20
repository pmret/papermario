.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B70B4_E201C4
/* E201C4 802B70B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E201C8 802B70B8 AFB10014 */  sw        $s1, 0x14($sp)
/* E201CC 802B70BC 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* E201D0 802B70C0 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* E201D4 802B70C4 AFBF0018 */  sw        $ra, 0x18($sp)
/* E201D8 802B70C8 AFB00010 */  sw        $s0, 0x10($sp)
/* E201DC 802B70CC 8E220004 */  lw        $v0, 4($s1)
/* E201E0 802B70D0 30420010 */  andi      $v0, $v0, 0x10
/* E201E4 802B70D4 1040003F */  beqz      $v0, .L802B71D4
/* E201E8 802B70D8 00000000 */   nop
/* E201EC 802B70DC 3C10802B */  lui       $s0, %hi(D_802B7CB8_E20DC8)
/* E201F0 802B70E0 26107CB8 */  addiu     $s0, $s0, %lo(D_802B7CB8_E20DC8)
/* E201F4 802B70E4 8E040000 */  lw        $a0, ($s0)
/* E201F8 802B70E8 0C00A580 */  jal       mem_clear
/* E201FC 802B70EC 24050028 */   addiu    $a1, $zero, 0x28
/* E20200 802B70F0 8E030000 */  lw        $v1, ($s0)
/* E20204 802B70F4 C6200028 */  lwc1      $f0, 0x28($s1)
/* E20208 802B70F8 2402FFFF */  addiu     $v0, $zero, -1
/* E2020C 802B70FC 3C018011 */  lui       $at, %hi(D_8010C950)
/* E20210 802B7100 AC22C950 */  sw        $v0, %lo(D_8010C950)($at)
/* E20214 802B7104 E4600000 */  swc1      $f0, ($v1)
/* E20218 802B7108 862200B0 */  lh        $v0, 0xb0($s1)
/* E2021C 802B710C C620002C */  lwc1      $f0, 0x2c($s1)
/* E20220 802B7110 44821000 */  mtc1      $v0, $f2
/* E20224 802B7114 00000000 */  nop
/* E20228 802B7118 468010A0 */  cvt.s.w   $f2, $f2
/* E2022C 802B711C 8E220004 */  lw        $v0, 4($s1)
/* E20230 802B7120 46020080 */  add.s     $f2, $f0, $f2
/* E20234 802B7124 30421000 */  andi      $v0, $v0, 0x1000
/* E20238 802B7128 3C014000 */  lui       $at, 0x4000
/* E2023C 802B712C 44810000 */  mtc1      $at, $f0
/* E20240 802B7130 14400004 */  bnez      $v0, .L802B7144
/* E20244 802B7134 24630004 */   addiu    $v1, $v1, 4
/* E20248 802B7138 3C014100 */  lui       $at, 0x4100
/* E2024C 802B713C 44810000 */  mtc1      $at, $f0
/* E20250 802B7140 00000000 */  nop
.L802B7144:
/* E20254 802B7144 46001000 */  add.s     $f0, $f2, $f0
/* E20258 802B7148 3C04802B */  lui       $a0, %hi(D_802B7CB8_E20DC8)
/* E2025C 802B714C 24847CB8 */  addiu     $a0, $a0, %lo(D_802B7CB8_E20DC8)
/* E20260 802B7150 E4600000 */  swc1      $f0, ($v1)
/* E20264 802B7154 8C820000 */  lw        $v0, ($a0)
/* E20268 802B7158 C6200030 */  lwc1      $f0, 0x30($s1)
/* E2026C 802B715C 3C013ECC */  lui       $at, 0x3ecc
/* E20270 802B7160 3421CCCD */  ori       $at, $at, 0xcccd
/* E20274 802B7164 44811000 */  mtc1      $at, $f2
/* E20278 802B7168 A0400023 */  sb        $zero, 0x23($v0)
/* E2027C 802B716C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E20280 802B7170 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E20284 802B7174 E4400008 */  swc1      $f0, 8($v0)
/* E20288 802B7178 E4420010 */  swc1      $f2, 0x10($v0)
/* E2028C 802B717C 3C02802B */  lui       $v0, %hi(func_802B7728_E20838)
/* E20290 802B7180 24427728 */  addiu     $v0, $v0, %lo(func_802B7728_E20838)
/* E20294 802B7184 3C018011 */  lui       $at, %hi(D_8010C958)
/* E20298 802B7188 AC22C958 */  sw        $v0, %lo(D_8010C958)($at)
/* E2029C 802B718C 00031080 */  sll       $v0, $v1, 2
/* E202A0 802B7190 00431021 */  addu      $v0, $v0, $v1
/* E202A4 802B7194 00021080 */  sll       $v0, $v0, 2
/* E202A8 802B7198 00431023 */  subu      $v0, $v0, $v1
/* E202AC 802B719C 000218C0 */  sll       $v1, $v0, 3
/* E202B0 802B71A0 00431021 */  addu      $v0, $v0, $v1
/* E202B4 802B71A4 000210C0 */  sll       $v0, $v0, 3
/* E202B8 802B71A8 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* E202BC 802B71AC 00220821 */  addu      $at, $at, $v0
/* E202C0 802B71B0 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* E202C4 802B71B4 240200FF */  addiu     $v0, $zero, 0xff
/* E202C8 802B71B8 8C830000 */  lw        $v1, ($a0)
/* E202CC 802B71BC 46000007 */  neg.s     $f0, $f0
/* E202D0 802B71C0 A0620024 */  sb        $v0, 0x24($v1)
/* E202D4 802B71C4 E460000C */  swc1      $f0, 0xc($v1)
/* E202D8 802B71C8 8C830000 */  lw        $v1, ($a0)
/* E202DC 802B71CC 240200FF */  addiu     $v0, $zero, 0xff
/* E202E0 802B71D0 AC62001C */  sw        $v0, 0x1c($v1)
.L802B71D4:
/* E202E4 802B71D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* E202E8 802B71D8 8FB10014 */  lw        $s1, 0x14($sp)
/* E202EC 802B71DC 8FB00010 */  lw        $s0, 0x10($sp)
/* E202F0 802B71E0 03E00008 */  jr        $ra
/* E202F4 802B71E4 27BD0020 */   addiu    $sp, $sp, 0x20
