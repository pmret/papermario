.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244078_9DB098
/* 9DB098 80244078 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 9DB09C 8024407C AFB40020 */  sw        $s4, 0x20($sp)
/* 9DB0A0 80244080 0080A02D */  daddu     $s4, $a0, $zero
/* 9DB0A4 80244084 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9DB0A8 80244088 0000982D */  daddu     $s3, $zero, $zero
/* 9DB0AC 8024408C AFB20018 */  sw        $s2, 0x18($sp)
/* 9DB0B0 80244090 3C128025 */  lui       $s2, %hi(D_80252784_9E97A4)
/* 9DB0B4 80244094 26522784 */  addiu     $s2, $s2, %lo(D_80252784_9E97A4)
/* 9DB0B8 80244098 AFBF0030 */  sw        $ra, 0x30($sp)
/* 9DB0BC 8024409C AFB7002C */  sw        $s7, 0x2c($sp)
/* 9DB0C0 802440A0 AFB60028 */  sw        $s6, 0x28($sp)
/* 9DB0C4 802440A4 AFB50024 */  sw        $s5, 0x24($sp)
/* 9DB0C8 802440A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9DB0CC 802440AC AFB00010 */  sw        $s0, 0x10($sp)
/* 9DB0D0 802440B0 8E82000C */  lw        $v0, 0xc($s4)
/* 9DB0D4 802440B4 0260882D */  daddu     $s1, $s3, $zero
/* 9DB0D8 802440B8 8C560000 */  lw        $s6, ($v0)
/* 9DB0DC 802440BC 26500010 */  addiu     $s0, $s2, 0x10
/* 9DB0E0 802440C0 0C0B1EAF */  jal       get_variable
/* 9DB0E4 802440C4 02C0282D */   daddu    $a1, $s6, $zero
/* 9DB0E8 802440C8 0280202D */  daddu     $a0, $s4, $zero
/* 9DB0EC 802440CC 2455FFFF */  addiu     $s5, $v0, -1
/* 9DB0F0 802440D0 001510C0 */  sll       $v0, $s5, 3
/* 9DB0F4 802440D4 00551023 */  subu      $v0, $v0, $s5
/* 9DB0F8 802440D8 00021080 */  sll       $v0, $v0, 2
/* 9DB0FC 802440DC 3C058025 */  lui       $a1, %hi(D_80252794_9E97B4)
/* 9DB100 802440E0 00A22821 */  addu      $a1, $a1, $v0
/* 9DB104 802440E4 8CA52794 */  lw        $a1, %lo(D_80252794_9E97B4)($a1)
/* 9DB108 802440E8 0C0B2026 */  jal       evt_set_variable
/* 9DB10C 802440EC 24060001 */   addiu    $a2, $zero, 1
.L802440F0:
/* 9DB110 802440F0 8E05FFFC */  lw        $a1, -4($s0)
/* 9DB114 802440F4 0C0B1EAF */  jal       get_variable
/* 9DB118 802440F8 0280202D */   daddu    $a0, $s4, $zero
/* 9DB11C 802440FC 5040000D */  beql      $v0, $zero, .L80244134
/* 9DB120 80244100 26310001 */   addiu    $s1, $s1, 1
/* 9DB124 80244104 8E050004 */  lw        $a1, 4($s0)
/* 9DB128 80244108 0C0B1EAF */  jal       get_variable
/* 9DB12C 8024410C 0280202D */   daddu    $a0, $s4, $zero
/* 9DB130 80244110 54400008 */  bnel      $v0, $zero, .L80244134
/* 9DB134 80244114 26310001 */   addiu    $s1, $s1, 1
/* 9DB138 80244118 26730001 */  addiu     $s3, $s3, 1
/* 9DB13C 8024411C 8E050000 */  lw        $a1, ($s0)
/* 9DB140 80244120 0C0B1EAF */  jal       get_variable
/* 9DB144 80244124 0280202D */   daddu    $a0, $s4, $zero
/* 9DB148 80244128 10400007 */  beqz      $v0, .L80244148
/* 9DB14C 8024412C 24020014 */   addiu    $v0, $zero, 0x14
/* 9DB150 80244130 26310001 */  addiu     $s1, $s1, 1
.L80244134:
/* 9DB154 80244134 2610001C */  addiu     $s0, $s0, 0x1c
/* 9DB158 80244138 2E220014 */  sltiu     $v0, $s1, 0x14
/* 9DB15C 8024413C 1440FFEC */  bnez      $v0, .L802440F0
/* 9DB160 80244140 2652001C */   addiu    $s2, $s2, 0x1c
/* 9DB164 80244144 24020014 */  addiu     $v0, $zero, 0x14
.L80244148:
/* 9DB168 80244148 16220024 */  bne       $s1, $v0, .L802441DC
/* 9DB16C 8024414C 0280202D */   daddu    $a0, $s4, $zero
/* 9DB170 80244150 2A620002 */  slti      $v0, $s3, 2
/* 9DB174 80244154 10400004 */  beqz      $v0, .L80244168
/* 9DB178 80244158 02C0282D */   daddu    $a1, $s6, $zero
/* 9DB17C 8024415C AE800084 */  sw        $zero, 0x84($s4)
/* 9DB180 80244160 0809107B */  j         .L802441EC
/* 9DB184 80244164 240600FF */   addiu    $a2, $zero, 0xff
.L80244168:
/* 9DB188 80244168 0C00A67F */  jal       rand_int
/* 9DB18C 8024416C 2664FFFE */   addiu    $a0, $s3, -2
/* 9DB190 80244170 0040B82D */  daddu     $s7, $v0, $zero
/* 9DB194 80244174 0000982D */  daddu     $s3, $zero, $zero
/* 9DB198 80244178 3C128025 */  lui       $s2, %hi(D_80252784_9E97A4)
/* 9DB19C 8024417C 26522784 */  addiu     $s2, $s2, %lo(D_80252784_9E97A4)
/* 9DB1A0 80244180 0260882D */  daddu     $s1, $s3, $zero
/* 9DB1A4 80244184 26500014 */  addiu     $s0, $s2, 0x14
.L80244188:
/* 9DB1A8 80244188 5235000F */  beql      $s1, $s5, .L802441C8
/* 9DB1AC 8024418C 26310001 */   addiu    $s1, $s1, 1
/* 9DB1B0 80244190 8E05FFF8 */  lw        $a1, -8($s0)
/* 9DB1B4 80244194 0C0B1EAF */  jal       get_variable
/* 9DB1B8 80244198 0280202D */   daddu    $a0, $s4, $zero
/* 9DB1BC 8024419C 5040000A */  beql      $v0, $zero, .L802441C8
/* 9DB1C0 802441A0 26310001 */   addiu    $s1, $s1, 1
/* 9DB1C4 802441A4 8E050000 */  lw        $a1, ($s0)
/* 9DB1C8 802441A8 0C0B1EAF */  jal       get_variable
/* 9DB1CC 802441AC 0280202D */   daddu    $a0, $s4, $zero
/* 9DB1D0 802441B0 54400005 */  bnel      $v0, $zero, .L802441C8
/* 9DB1D4 802441B4 26310001 */   addiu    $s1, $s1, 1
/* 9DB1D8 802441B8 0260102D */  daddu     $v0, $s3, $zero
/* 9DB1DC 802441BC 10570006 */  beq       $v0, $s7, .L802441D8
/* 9DB1E0 802441C0 26730001 */   addiu    $s3, $s3, 1
/* 9DB1E4 802441C4 26310001 */  addiu     $s1, $s1, 1
.L802441C8:
/* 9DB1E8 802441C8 2610001C */  addiu     $s0, $s0, 0x1c
/* 9DB1EC 802441CC 2E220014 */  sltiu     $v0, $s1, 0x14
/* 9DB1F0 802441D0 1440FFED */  bnez      $v0, .L80244188
/* 9DB1F4 802441D4 2652001C */   addiu    $s2, $s2, 0x1c
.L802441D8:
/* 9DB1F8 802441D8 0280202D */  daddu     $a0, $s4, $zero
.L802441DC:
/* 9DB1FC 802441DC 02C0282D */  daddu     $a1, $s6, $zero
/* 9DB200 802441E0 8E420000 */  lw        $v0, ($s2)
/* 9DB204 802441E4 26260001 */  addiu     $a2, $s1, 1
/* 9DB208 802441E8 AC820084 */  sw        $v0, 0x84($a0)
.L802441EC:
/* 9DB20C 802441EC 0C0B2026 */  jal       evt_set_variable
/* 9DB210 802441F0 00000000 */   nop
/* 9DB214 802441F4 24020002 */  addiu     $v0, $zero, 2
/* 9DB218 802441F8 8FBF0030 */  lw        $ra, 0x30($sp)
/* 9DB21C 802441FC 8FB7002C */  lw        $s7, 0x2c($sp)
/* 9DB220 80244200 8FB60028 */  lw        $s6, 0x28($sp)
/* 9DB224 80244204 8FB50024 */  lw        $s5, 0x24($sp)
/* 9DB228 80244208 8FB40020 */  lw        $s4, 0x20($sp)
/* 9DB22C 8024420C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9DB230 80244210 8FB20018 */  lw        $s2, 0x18($sp)
/* 9DB234 80244214 8FB10014 */  lw        $s1, 0x14($sp)
/* 9DB238 80244218 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DB23C 8024421C 03E00008 */  jr        $ra
/* 9DB240 80244220 27BD0038 */   addiu    $sp, $sp, 0x38
