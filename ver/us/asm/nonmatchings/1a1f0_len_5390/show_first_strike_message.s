.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel show_first_strike_message
/* 1D05C 80041C5C 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 1D060 80041C60 3C05800B */  lui       $a1, %hi(gCurrentEncounter)
/* 1D064 80041C64 24A50F10 */  addiu     $a1, $a1, %lo(gCurrentEncounter)
/* 1D068 80041C68 AFBF0054 */  sw        $ra, 0x54($sp)
/* 1D06C 80041C6C AFB00050 */  sw        $s0, 0x50($sp)
/* 1D070 80041C70 8CA20094 */  lw        $v0, 0x94($a1)
/* 1D074 80041C74 14400005 */  bnez      $v0, .L80041C8C
/* 1D078 80041C78 2402FF38 */   addiu    $v0, $zero, -0xc8
/* 1D07C 80041C7C 3C01800A */  lui       $at, %hi(D_8009A668)
/* 1D080 80041C80 A422A668 */  sh        $v0, %lo(D_8009A668)($at)
/* 1D084 80041C84 080107C0 */  j         .L80041F00
/* 1D088 80041C88 00000000 */   nop
.L80041C8C:
/* 1D08C 80041C8C 3C02800A */  lui       $v0, %hi(D_8009A668)
/* 1D090 80041C90 2442A668 */  addiu     $v0, $v0, %lo(D_8009A668)
/* 1D094 80041C94 94430000 */  lhu       $v1, ($v0)
/* 1D098 80041C98 24630028 */  addiu     $v1, $v1, 0x28
/* 1D09C 80041C9C 00032400 */  sll       $a0, $v1, 0x10
/* 1D0A0 80041CA0 00048403 */  sra       $s0, $a0, 0x10
/* 1D0A4 80041CA4 1A000005 */  blez      $s0, .L80041CBC
/* 1D0A8 80041CA8 A4430000 */   sh       $v1, ($v0)
/* 1D0AC 80041CAC 2A020640 */  slti      $v0, $s0, 0x640
/* 1D0B0 80041CB0 10400002 */  beqz      $v0, .L80041CBC
/* 1D0B4 80041CB4 2610F9C0 */   addiu    $s0, $s0, -0x640
/* 1D0B8 80041CB8 0000802D */  daddu     $s0, $zero, $zero
.L80041CBC:
/* 1D0BC 80041CBC 80A30004 */  lb        $v1, 4($a1)
/* 1D0C0 80041CC0 24020001 */  addiu     $v0, $zero, 1
/* 1D0C4 80041CC4 10620005 */  beq       $v1, $v0, .L80041CDC
/* 1D0C8 80041CC8 24020002 */   addiu    $v0, $zero, 2
/* 1D0CC 80041CCC 1062005D */  beq       $v1, $v0, .L80041E44
/* 1D0D0 80041CD0 00000000 */   nop
/* 1D0D4 80041CD4 080107C0 */  j         .L80041F00
/* 1D0D8 80041CD8 00000000 */   nop
.L80041CDC:
/* 1D0DC 80041CDC 80A30005 */  lb        $v1, 5($a1)
/* 1D0E0 80041CE0 24020004 */  addiu     $v0, $zero, 4
/* 1D0E4 80041CE4 1062000C */  beq       $v1, $v0, .L80041D18
/* 1D0E8 80041CE8 28620005 */   slti     $v0, $v1, 5
/* 1D0EC 80041CEC 10400005 */  beqz      $v0, .L80041D04
/* 1D0F0 80041CF0 24020002 */   addiu    $v0, $zero, 2
/* 1D0F4 80041CF4 10620009 */  beq       $v1, $v0, .L80041D1C
/* 1D0F8 80041CF8 3C04001D */   lui      $a0, 0x1d
/* 1D0FC 80041CFC 080107C0 */  j         .L80041F00
/* 1D100 80041D00 00000000 */   nop
.L80041D04:
/* 1D104 80041D04 24020006 */  addiu     $v0, $zero, 6
/* 1D108 80041D08 10620029 */  beq       $v1, $v0, .L80041DB0
/* 1D10C 80041D0C 3C04001D */   lui      $a0, 0x1d
/* 1D110 80041D10 080107C0 */  j         .L80041F00
/* 1D114 80041D14 00000000 */   nop
.L80041D18:
/* 1D118 80041D18 3C04001D */  lui       $a0, 0x1d
.L80041D1C:
/* 1D11C 80041D1C 348400AC */  ori       $a0, $a0, 0xac
/* 1D120 80041D20 0C04991D */  jal       get_string_width
/* 1D124 80041D24 0000282D */   daddu    $a1, $zero, $zero
/* 1D128 80041D28 24480018 */  addiu     $t0, $v0, 0x18
/* 1D12C 80041D2C 260300A0 */  addiu     $v1, $s0, 0xa0
/* 1D130 80041D30 000817C2 */  srl       $v0, $t0, 0x1f
/* 1D134 80041D34 01021021 */  addu      $v0, $t0, $v0
/* 1D138 80041D38 00021043 */  sra       $v0, $v0, 1
/* 1D13C 80041D3C 00628023 */  subu      $s0, $v1, $v0
/* 1D140 80041D40 0000202D */  daddu     $a0, $zero, $zero
/* 1D144 80041D44 24050014 */  addiu     $a1, $zero, 0x14
/* 1D148 80041D48 0200302D */  daddu     $a2, $s0, $zero
/* 1D14C 80041D4C 24070045 */  addiu     $a3, $zero, 0x45
/* 1D150 80041D50 2402001C */  addiu     $v0, $zero, 0x1c
/* 1D154 80041D54 AFA20018 */  sw        $v0, 0x18($sp)
/* 1D158 80041D58 240200FF */  addiu     $v0, $zero, 0xff
/* 1D15C 80041D5C AFA2001C */  sw        $v0, 0x1c($sp)
/* 1D160 80041D60 24020140 */  addiu     $v0, $zero, 0x140
/* 1D164 80041D64 AFA20044 */  sw        $v0, 0x44($sp)
/* 1D168 80041D68 240200F0 */  addiu     $v0, $zero, 0xf0
/* 1D16C 80041D6C AFA00010 */  sw        $zero, 0x10($sp)
/* 1D170 80041D70 AFA80014 */  sw        $t0, 0x14($sp)
/* 1D174 80041D74 AFA00020 */  sw        $zero, 0x20($sp)
/* 1D178 80041D78 AFA00024 */  sw        $zero, 0x24($sp)
/* 1D17C 80041D7C AFA00028 */  sw        $zero, 0x28($sp)
/* 1D180 80041D80 AFA0002C */  sw        $zero, 0x2c($sp)
/* 1D184 80041D84 AFA00030 */  sw        $zero, 0x30($sp)
/* 1D188 80041D88 AFA00034 */  sw        $zero, 0x34($sp)
/* 1D18C 80041D8C AFA00038 */  sw        $zero, 0x38($sp)
/* 1D190 80041D90 AFA0003C */  sw        $zero, 0x3c($sp)
/* 1D194 80041D94 AFA00040 */  sw        $zero, 0x40($sp)
/* 1D198 80041D98 AFA20048 */  sw        $v0, 0x48($sp)
/* 1D19C 80041D9C 0C03D4B8 */  jal       draw_box
/* 1D1A0 80041DA0 AFA0004C */   sw       $zero, 0x4c($sp)
/* 1D1A4 80041DA4 3C04001D */  lui       $a0, 0x1d
/* 1D1A8 80041DA8 080107B9 */  j         .L80041EE4
/* 1D1AC 80041DAC 348400AC */   ori      $a0, $a0, 0xac
.L80041DB0:
/* 1D1B0 80041DB0 348400AD */  ori       $a0, $a0, 0xad
/* 1D1B4 80041DB4 0C04991D */  jal       get_string_width
/* 1D1B8 80041DB8 0000282D */   daddu    $a1, $zero, $zero
/* 1D1BC 80041DBC 24480018 */  addiu     $t0, $v0, 0x18
/* 1D1C0 80041DC0 260300A0 */  addiu     $v1, $s0, 0xa0
/* 1D1C4 80041DC4 000817C2 */  srl       $v0, $t0, 0x1f
/* 1D1C8 80041DC8 01021021 */  addu      $v0, $t0, $v0
/* 1D1CC 80041DCC 00021043 */  sra       $v0, $v0, 1
/* 1D1D0 80041DD0 00628023 */  subu      $s0, $v1, $v0
/* 1D1D4 80041DD4 0000202D */  daddu     $a0, $zero, $zero
/* 1D1D8 80041DD8 24050014 */  addiu     $a1, $zero, 0x14
/* 1D1DC 80041DDC 0200302D */  daddu     $a2, $s0, $zero
/* 1D1E0 80041DE0 24070045 */  addiu     $a3, $zero, 0x45
/* 1D1E4 80041DE4 2402001C */  addiu     $v0, $zero, 0x1c
/* 1D1E8 80041DE8 AFA20018 */  sw        $v0, 0x18($sp)
/* 1D1EC 80041DEC 240200FF */  addiu     $v0, $zero, 0xff
/* 1D1F0 80041DF0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 1D1F4 80041DF4 24020140 */  addiu     $v0, $zero, 0x140
/* 1D1F8 80041DF8 AFA20044 */  sw        $v0, 0x44($sp)
/* 1D1FC 80041DFC 240200F0 */  addiu     $v0, $zero, 0xf0
/* 1D200 80041E00 AFA00010 */  sw        $zero, 0x10($sp)
/* 1D204 80041E04 AFA80014 */  sw        $t0, 0x14($sp)
/* 1D208 80041E08 AFA00020 */  sw        $zero, 0x20($sp)
/* 1D20C 80041E0C AFA00024 */  sw        $zero, 0x24($sp)
/* 1D210 80041E10 AFA00028 */  sw        $zero, 0x28($sp)
/* 1D214 80041E14 AFA0002C */  sw        $zero, 0x2c($sp)
/* 1D218 80041E18 AFA00030 */  sw        $zero, 0x30($sp)
/* 1D21C 80041E1C AFA00034 */  sw        $zero, 0x34($sp)
/* 1D220 80041E20 AFA00038 */  sw        $zero, 0x38($sp)
/* 1D224 80041E24 AFA0003C */  sw        $zero, 0x3c($sp)
/* 1D228 80041E28 AFA00040 */  sw        $zero, 0x40($sp)
/* 1D22C 80041E2C AFA20048 */  sw        $v0, 0x48($sp)
/* 1D230 80041E30 0C03D4B8 */  jal       draw_box
/* 1D234 80041E34 AFA0004C */   sw       $zero, 0x4c($sp)
/* 1D238 80041E38 3C04001D */  lui       $a0, 0x1d
/* 1D23C 80041E3C 080107B9 */  j         .L80041EE4
/* 1D240 80041E40 348400AD */   ori      $a0, $a0, 0xad
.L80041E44:
/* 1D244 80041E44 0C03A752 */  jal       is_ability_active
/* 1D248 80041E48 24040011 */   addiu    $a0, $zero, 0x11
/* 1D24C 80041E4C 1440002C */  bnez      $v0, .L80041F00
/* 1D250 80041E50 3C04001D */   lui      $a0, 0x1d
/* 1D254 80041E54 348400AE */  ori       $a0, $a0, 0xae
/* 1D258 80041E58 0C04991D */  jal       get_string_width
/* 1D25C 80041E5C 0000282D */   daddu    $a1, $zero, $zero
/* 1D260 80041E60 24480018 */  addiu     $t0, $v0, 0x18
/* 1D264 80041E64 260300A0 */  addiu     $v1, $s0, 0xa0
/* 1D268 80041E68 000817C2 */  srl       $v0, $t0, 0x1f
/* 1D26C 80041E6C 01021021 */  addu      $v0, $t0, $v0
/* 1D270 80041E70 00021043 */  sra       $v0, $v0, 1
/* 1D274 80041E74 00628023 */  subu      $s0, $v1, $v0
/* 1D278 80041E78 0000202D */  daddu     $a0, $zero, $zero
/* 1D27C 80041E7C 24050004 */  addiu     $a1, $zero, 4
/* 1D280 80041E80 0200302D */  daddu     $a2, $s0, $zero
/* 1D284 80041E84 24070045 */  addiu     $a3, $zero, 0x45
/* 1D288 80041E88 2402001C */  addiu     $v0, $zero, 0x1c
/* 1D28C 80041E8C AFA20018 */  sw        $v0, 0x18($sp)
/* 1D290 80041E90 240200FF */  addiu     $v0, $zero, 0xff
/* 1D294 80041E94 AFA2001C */  sw        $v0, 0x1c($sp)
/* 1D298 80041E98 24020140 */  addiu     $v0, $zero, 0x140
/* 1D29C 80041E9C AFA20044 */  sw        $v0, 0x44($sp)
/* 1D2A0 80041EA0 240200F0 */  addiu     $v0, $zero, 0xf0
/* 1D2A4 80041EA4 AFA00010 */  sw        $zero, 0x10($sp)
/* 1D2A8 80041EA8 AFA80014 */  sw        $t0, 0x14($sp)
/* 1D2AC 80041EAC AFA00020 */  sw        $zero, 0x20($sp)
/* 1D2B0 80041EB0 AFA00024 */  sw        $zero, 0x24($sp)
/* 1D2B4 80041EB4 AFA00028 */  sw        $zero, 0x28($sp)
/* 1D2B8 80041EB8 AFA0002C */  sw        $zero, 0x2c($sp)
/* 1D2BC 80041EBC AFA00030 */  sw        $zero, 0x30($sp)
/* 1D2C0 80041EC0 AFA00034 */  sw        $zero, 0x34($sp)
/* 1D2C4 80041EC4 AFA00038 */  sw        $zero, 0x38($sp)
/* 1D2C8 80041EC8 AFA0003C */  sw        $zero, 0x3c($sp)
/* 1D2CC 80041ECC AFA00040 */  sw        $zero, 0x40($sp)
/* 1D2D0 80041ED0 AFA20048 */  sw        $v0, 0x48($sp)
/* 1D2D4 80041ED4 0C03D4B8 */  jal       draw_box
/* 1D2D8 80041ED8 AFA0004C */   sw       $zero, 0x4c($sp)
/* 1D2DC 80041EDC 3C04001D */  lui       $a0, 0x1d
/* 1D2E0 80041EE0 348400AE */  ori       $a0, $a0, 0xae
.L80041EE4:
/* 1D2E4 80041EE4 2605000B */  addiu     $a1, $s0, 0xb
/* 1D2E8 80041EE8 2406004B */  addiu     $a2, $zero, 0x4b
/* 1D2EC 80041EEC 240700FF */  addiu     $a3, $zero, 0xff
/* 1D2F0 80041EF0 2402000A */  addiu     $v0, $zero, 0xa
/* 1D2F4 80041EF4 AFA20010 */  sw        $v0, 0x10($sp)
/* 1D2F8 80041EF8 0C04993B */  jal       draw_string
/* 1D2FC 80041EFC AFA00014 */   sw       $zero, 0x14($sp)
.L80041F00:
/* 1D300 80041F00 8FBF0054 */  lw        $ra, 0x54($sp)
/* 1D304 80041F04 8FB00050 */  lw        $s0, 0x50($sp)
/* 1D308 80041F08 03E00008 */  jr        $ra
/* 1D30C 80041F0C 27BD0058 */   addiu    $sp, $sp, 0x58
