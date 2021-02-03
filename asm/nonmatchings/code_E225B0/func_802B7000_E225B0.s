.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B7000_E225B0
/* E225B0 802B7000 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x4)
/* E225B4 802B7004 8C42EFCC */  lw        $v0, %lo(gPlayerStatus+0x4)($v0)
/* E225B8 802B7008 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* E225BC 802B700C AFBF00C8 */  sw        $ra, 0xc8($sp)
/* E225C0 802B7010 AFB300C4 */  sw        $s3, 0xc4($sp)
/* E225C4 802B7014 AFB200C0 */  sw        $s2, 0xc0($sp)
/* E225C8 802B7018 AFB100BC */  sw        $s1, 0xbc($sp)
/* E225CC 802B701C 30420100 */  andi      $v0, $v0, 0x100
/* E225D0 802B7020 104000A0 */  beqz      $v0, .L802B72A4
/* E225D4 802B7024 AFB000B8 */   sw       $s0, 0xb8($sp)
/* E225D8 802B7028 3C13802B */  lui       $s3, %hi(D_802B7C78_E23228)
/* E225DC 802B702C 26737C78 */  addiu     $s3, $s3, %lo(D_802B7C78_E23228)
/* E225E0 802B7030 8E620000 */  lw        $v0, ($s3)
/* E225E4 802B7034 27A40020 */  addiu     $a0, $sp, 0x20
/* E225E8 802B7038 8C45000C */  lw        $a1, 0xc($v0)
/* E225EC 802B703C 3C120001 */  lui       $s2, 1
/* E225F0 802B7040 00A0302D */  daddu     $a2, $a1, $zero
/* E225F4 802B7044 0C019DF0 */  jal       guScaleF
/* E225F8 802B7048 00A0382D */   daddu    $a3, $a1, $zero
/* E225FC 802B704C 27B00060 */  addiu     $s0, $sp, 0x60
/* E22600 802B7050 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E22604 802B7054 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E22608 802B7058 44800000 */  mtc1      $zero, $f0
/* E2260C 802B705C 00031080 */  sll       $v0, $v1, 2
/* E22610 802B7060 00431021 */  addu      $v0, $v0, $v1
/* E22614 802B7064 00021080 */  sll       $v0, $v0, 2
/* E22618 802B7068 00431023 */  subu      $v0, $v0, $v1
/* E2261C 802B706C 000218C0 */  sll       $v1, $v0, 3
/* E22620 802B7070 00431021 */  addu      $v0, $v0, $v1
/* E22624 802B7074 000210C0 */  sll       $v0, $v0, 3
/* E22628 802B7078 44060000 */  mfc1      $a2, $f0
/* E2262C 802B707C 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* E22630 802B7080 00220821 */  addu      $at, $at, $v0
/* E22634 802B7084 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* E22638 802B7088 3C073F80 */  lui       $a3, 0x3f80
/* E2263C 802B708C 46000007 */  neg.s     $f0, $f0
/* E22640 802B7090 44050000 */  mfc1      $a1, $f0
/* E22644 802B7094 0200202D */  daddu     $a0, $s0, $zero
/* E22648 802B7098 0C019EC8 */  jal       guRotateF
/* E2264C 802B709C AFA60010 */   sw       $a2, 0x10($sp)
/* E22650 802B70A0 27A40020 */  addiu     $a0, $sp, 0x20
/* E22654 802B70A4 0200282D */  daddu     $a1, $s0, $zero
/* E22658 802B70A8 0C019D80 */  jal       guMtxCatF
/* E2265C 802B70AC 0080302D */   daddu    $a2, $a0, $zero
/* E22660 802B70B0 8E620000 */  lw        $v0, ($s3)
/* E22664 802B70B4 36521630 */  ori       $s2, $s2, 0x1630
/* E22668 802B70B8 8C450000 */  lw        $a1, ($v0)
/* E2266C 802B70BC 8C460004 */  lw        $a2, 4($v0)
/* E22670 802B70C0 8C470008 */  lw        $a3, 8($v0)
/* E22674 802B70C4 0C019E40 */  jal       guTranslateF
/* E22678 802B70C8 0200202D */   daddu    $a0, $s0, $zero
/* E2267C 802B70CC 27A40020 */  addiu     $a0, $sp, 0x20
/* E22680 802B70D0 0200282D */  daddu     $a1, $s0, $zero
/* E22684 802B70D4 0C019D80 */  jal       guMtxCatF
/* E22688 802B70D8 0200302D */   daddu    $a2, $s0, $zero
/* E2268C 802B70DC 0200202D */  daddu     $a0, $s0, $zero
/* E22690 802B70E0 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* E22694 802B70E4 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* E22698 802B70E8 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* E2269C 802B70EC 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* E226A0 802B70F0 96050000 */  lhu       $a1, ($s0)
/* E226A4 802B70F4 8E220000 */  lw        $v0, ($s1)
/* E226A8 802B70F8 00052980 */  sll       $a1, $a1, 6
/* E226AC 802B70FC 00B22821 */  addu      $a1, $a1, $s2
/* E226B0 802B7100 0C019D40 */  jal       guMtxF2L
/* E226B4 802B7104 00452821 */   addu     $a1, $v0, $a1
/* E226B8 802B7108 3C03DA38 */  lui       $v1, 0xda38
/* E226BC 802B710C 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* E226C0 802B7110 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* E226C4 802B7114 34630002 */  ori       $v1, $v1, 2
/* E226C8 802B7118 8CA40000 */  lw        $a0, ($a1)
/* E226CC 802B711C 96020000 */  lhu       $v0, ($s0)
/* E226D0 802B7120 0080302D */  daddu     $a2, $a0, $zero
/* E226D4 802B7124 24840008 */  addiu     $a0, $a0, 8
/* E226D8 802B7128 ACA40000 */  sw        $a0, ($a1)
/* E226DC 802B712C ACC30000 */  sw        $v1, ($a2)
/* E226E0 802B7130 24430001 */  addiu     $v1, $v0, 1
/* E226E4 802B7134 3042FFFF */  andi      $v0, $v0, 0xffff
/* E226E8 802B7138 00021180 */  sll       $v0, $v0, 6
/* E226EC 802B713C A6030000 */  sh        $v1, ($s0)
/* E226F0 802B7140 8E230000 */  lw        $v1, ($s1)
/* E226F4 802B7144 00521021 */  addu      $v0, $v0, $s2
/* E226F8 802B7148 00621821 */  addu      $v1, $v1, $v0
/* E226FC 802B714C 3C02DE00 */  lui       $v0, 0xde00
/* E22700 802B7150 ACC30004 */  sw        $v1, 4($a2)
/* E22704 802B7154 AC820000 */  sw        $v0, ($a0)
/* E22708 802B7158 8E630000 */  lw        $v1, ($s3)
/* E2270C 802B715C 3C02802B */  lui       $v0, %hi(D_802B7C00_E231B0)
/* E22710 802B7160 24427C00 */  addiu     $v0, $v0, %lo(D_802B7C00_E231B0)
/* E22714 802B7164 AC820004 */  sw        $v0, 4($a0)
/* E22718 802B7168 8C620018 */  lw        $v0, 0x18($v1)
/* E2271C 802B716C 24840008 */  addiu     $a0, $a0, 8
/* E22720 802B7170 2842002F */  slti      $v0, $v0, 0x2f
/* E22724 802B7174 10400004 */  beqz      $v0, .L802B7188
/* E22728 802B7178 ACA40000 */   sw       $a0, ($a1)
/* E2272C 802B717C 8C620020 */  lw        $v0, 0x20($v1)
/* E22730 802B7180 24420001 */  addiu     $v0, $v0, 1
/* E22734 802B7184 AC620020 */  sw        $v0, 0x20($v1)
.L802B7188:
/* E22738 802B7188 8E620000 */  lw        $v0, ($s3)
/* E2273C 802B718C 3C032AAA */  lui       $v1, 0x2aaa
/* E22740 802B7190 8C440020 */  lw        $a0, 0x20($v0)
/* E22744 802B7194 3463AAAB */  ori       $v1, $v1, 0xaaab
/* E22748 802B7198 00830018 */  mult      $a0, $v1
/* E2274C 802B719C 000417C3 */  sra       $v0, $a0, 0x1f
/* E22750 802B71A0 00004010 */  mfhi      $t0
/* E22754 802B71A4 00081843 */  sra       $v1, $t0, 1
/* E22758 802B71A8 00621823 */  subu      $v1, $v1, $v0
/* E2275C 802B71AC 00031040 */  sll       $v0, $v1, 1
/* E22760 802B71B0 00431021 */  addu      $v0, $v0, $v1
/* E22764 802B71B4 00021080 */  sll       $v0, $v0, 2
/* E22768 802B71B8 00822023 */  subu      $a0, $a0, $v0
/* E2276C 802B71BC 2C82000C */  sltiu     $v0, $a0, 0xc
/* E22770 802B71C0 10400011 */  beqz      $v0, .L802B7208
/* E22774 802B71C4 00041080 */   sll      $v0, $a0, 2
/* E22778 802B71C8 3C01802B */  lui       $at, %hi(jtbl_802B7C80_E23230)
/* E2277C 802B71CC 00220821 */  addu      $at, $at, $v0
/* E22780 802B71D0 8C227C80 */  lw        $v0, %lo(jtbl_802B7C80_E23230)($at)
/* E22784 802B71D4 00400008 */  jr        $v0
/* E22788 802B71D8 00000000 */   nop
glabel L802B71DC_E2278C
/* E2278C 802B71DC 3C02802B */  lui       $v0, %hi(D_802B7BA0_E23150)
/* E22790 802B71E0 24427BA0 */  addiu     $v0, $v0, %lo(D_802B7BA0_E23150)
/* E22794 802B71E4 080ADC82 */  j         .L802B7208
/* E22798 802B71E8 AFA200A4 */   sw       $v0, 0xa4($sp)
glabel L802B71EC_E2279C
/* E2279C 802B71EC 3C02802B */  lui       $v0, %hi(D_802B7BC0_E23170)
/* E227A0 802B71F0 24427BC0 */  addiu     $v0, $v0, %lo(D_802B7BC0_E23170)
/* E227A4 802B71F4 080ADC82 */  j         .L802B7208
/* E227A8 802B71F8 AFA200A4 */   sw       $v0, 0xa4($sp)
glabel L802B71FC_E227AC
/* E227AC 802B71FC 3C02802B */  lui       $v0, %hi(D_802B7BE0_E23190)
/* E227B0 802B7200 24427BE0 */  addiu     $v0, $v0, %lo(D_802B7BE0_E23190)
/* E227B4 802B7204 AFA200A4 */  sw        $v0, 0xa4($sp)
.L802B7208:
/* E227B8 802B7208 0000202D */  daddu     $a0, $zero, $zero
/* E227BC 802B720C 24050007 */  addiu     $a1, $zero, 7
/* E227C0 802B7210 240600FF */  addiu     $a2, $zero, 0xff
/* E227C4 802B7214 3C02802B */  lui       $v0, %hi(D_802B7C78_E23228)
/* E227C8 802B7218 8C427C78 */  lw        $v0, %lo(D_802B7C78_E23228)($v0)
/* E227CC 802B721C 00C0802D */  daddu     $s0, $a2, $zero
/* E227D0 802B7220 AFB00010 */  sw        $s0, 0x10($sp)
/* E227D4 802B7224 8C420028 */  lw        $v0, 0x28($v0)
/* E227D8 802B7228 00C0382D */  daddu     $a3, $a2, $zero
/* E227DC 802B722C AFA00018 */  sw        $zero, 0x18($sp)
/* E227E0 802B7230 0C04EAA7 */  jal       func_8013AA9C
/* E227E4 802B7234 AFA20014 */   sw       $v0, 0x14($sp)
/* E227E8 802B7238 0000202D */  daddu     $a0, $zero, $zero
/* E227EC 802B723C 27A500A0 */  addiu     $a1, $sp, 0xa0
/* E227F0 802B7240 0080302D */  daddu     $a2, $a0, $zero
/* E227F4 802B7244 27A70060 */  addiu     $a3, $sp, 0x60
/* E227F8 802B7248 3C02802B */  lui       $v0, %hi(D_802B7580_E22B30)
/* E227FC 802B724C 24427580 */  addiu     $v0, $v0, %lo(D_802B7580_E22B30)
/* E22800 802B7250 AFA200A0 */  sw        $v0, 0xa0($sp)
/* E22804 802B7254 24020038 */  addiu     $v0, $zero, 0x38
/* E22808 802B7258 A7A200A8 */  sh        $v0, 0xa8($sp)
/* E2280C 802B725C A7A200AA */  sh        $v0, 0xaa($sp)
/* E22810 802B7260 2402FFE4 */  addiu     $v0, $zero, -0x1c
/* E22814 802B7264 A7A200AC */  sh        $v0, 0xac($sp)
/* E22818 802B7268 2402002E */  addiu     $v0, $zero, 0x2e
/* E2281C 802B726C A7A200AE */  sh        $v0, 0xae($sp)
/* E22820 802B7270 0C04EBDC */  jal       func_8013AF70
/* E22824 802B7274 A3B000B0 */   sb       $s0, 0xb0($sp)
/* E22828 802B7278 3C05D838 */  lui       $a1, 0xd838
/* E2282C 802B727C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* E22830 802B7280 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* E22834 802B7284 8C620000 */  lw        $v0, ($v1)
/* E22838 802B7288 34A50002 */  ori       $a1, $a1, 2
/* E2283C 802B728C 0040202D */  daddu     $a0, $v0, $zero
/* E22840 802B7290 24420008 */  addiu     $v0, $v0, 8
/* E22844 802B7294 AC620000 */  sw        $v0, ($v1)
/* E22848 802B7298 24020040 */  addiu     $v0, $zero, 0x40
/* E2284C 802B729C AC850000 */  sw        $a1, ($a0)
/* E22850 802B72A0 AC820004 */  sw        $v0, 4($a0)
.L802B72A4:
/* E22854 802B72A4 8FBF00C8 */  lw        $ra, 0xc8($sp)
/* E22858 802B72A8 8FB300C4 */  lw        $s3, 0xc4($sp)
/* E2285C 802B72AC 8FB200C0 */  lw        $s2, 0xc0($sp)
/* E22860 802B72B0 8FB100BC */  lw        $s1, 0xbc($sp)
/* E22864 802B72B4 8FB000B8 */  lw        $s0, 0xb8($sp)
/* E22868 802B72B8 03E00008 */  jr        $ra
/* E2286C 802B72BC 27BD00D0 */   addiu    $sp, $sp, 0xd0
