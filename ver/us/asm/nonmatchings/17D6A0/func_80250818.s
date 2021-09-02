.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8029D048
.word L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L802508C0_17F1A0, L802508C0_17F1A0, L802508C0_17F1A0, L802508C0_17F1A0, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L802508C0_17F1A0, L802508C0_17F1A0, L802508C0_17F1A0, L802508C0_17F1A0, L802508C0_17F1A0, L802508C0_17F1A0, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L802509DC_17F2BC, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250868_17F148, L80250988_17F268, L80250988_17F268, L80250988_17F268, L80250988_17F268, L80250988_17F268, L80250988_17F268, L80250988_17F268, L80250868_17F148, L8025090C_17F1EC, L80250868_17F148, L80250868_17F148, L80250868_17F148, 0

glabel jtbl_8029D1A0
.word L80250A88_17F368, L80250AA0_17F380, L80250B00_17F3E0, L80250B18_17F3F8, L80250B30_17F410, L80250B58_17F438, L80250E80_17F760, L80250E80_17F760, L80250BB0_17F490, L80250E80_17F760, L80250C54_17F534, L80250E80_17F760, L80250C9C_17F57C, L80250E80_17F760, L80250D00_17F5E0, L80250D18_17F5F8, L80250D60_17F640, L80250E80_17F760, L80250E3C_17F71C, L80250E3C_17F71C

.section .text

glabel func_80250818
/* 17F0F8 80250818 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 17F0FC 8025081C AFB20020 */  sw        $s2, 0x20($sp)
/* 17F100 80250820 24B2000F */  addiu     $s2, $a1, 0xf
/* 17F104 80250824 AFB30024 */  sw        $s3, 0x24($sp)
/* 17F108 80250828 0080982D */  daddu     $s3, $a0, $zero
/* 17F10C 8025082C AFBF002C */  sw        $ra, 0x2c($sp)
/* 17F110 80250830 AFB40028 */  sw        $s4, 0x28($sp)
/* 17F114 80250834 AFB1001C */  sw        $s1, 0x1c($sp)
/* 17F118 80250838 AFB00018 */  sw        $s0, 0x18($sp)
/* 17F11C 8025083C F7B40030 */  sdc1      $f20, 0x30($sp)
/* 17F120 80250840 86630012 */  lh        $v1, 0x12($s3)
/* 17F124 80250844 2C620055 */  sltiu     $v0, $v1, 0x55
/* 17F128 80250848 1040018D */  beqz      $v0, L80250E80_17F760
/* 17F12C 8025084C 24D10006 */   addiu    $s1, $a2, 6
/* 17F130 80250850 00031080 */  sll       $v0, $v1, 2
/* 17F134 80250854 3C01802A */  lui       $at, %hi(jtbl_8029D048)
/* 17F138 80250858 00220821 */  addu      $at, $at, $v0
/* 17F13C 8025085C 8C22D048 */  lw        $v0, %lo(jtbl_8029D048)($at)
/* 17F140 80250860 00400008 */  jr        $v0
/* 17F144 80250864 00000000 */   nop
glabel L80250868_17F148
/* 17F148 80250868 86620012 */  lh        $v0, 0x12($s3)
/* 17F14C 8025086C 00021080 */  sll       $v0, $v0, 2
/* 17F150 80250870 3C108028 */  lui       $s0, %hi(bMessages)
/* 17F154 80250874 02028021 */  addu      $s0, $s0, $v0
/* 17F158 80250878 8E103770 */  lw        $s0, %lo(bMessages)($s0)
/* 17F15C 8025087C 0C04992C */  jal       get_msg_lines
/* 17F160 80250880 0200202D */   daddu    $a0, $s0, $zero
/* 17F164 80250884 2443FFFF */  addiu     $v1, $v0, -1
/* 17F168 80250888 0200202D */  daddu     $a0, $s0, $zero
/* 17F16C 8025088C 0240282D */  daddu     $a1, $s2, $zero
/* 17F170 80250890 240700FF */  addiu     $a3, $zero, 0xff
/* 17F174 80250894 00031040 */  sll       $v0, $v1, 1
/* 17F178 80250898 3C068028 */  lui       $a2, %hi(D_802835D4)
/* 17F17C 8025089C 00C23021 */  addu      $a2, $a2, $v0
/* 17F180 802508A0 84C635D4 */  lh        $a2, %lo(D_802835D4)($a2)
/* 17F184 802508A4 2402000F */  addiu     $v0, $zero, 0xf
/* 17F188 802508A8 AFA20010 */  sw        $v0, 0x10($sp)
/* 17F18C 802508AC AFA00014 */  sw        $zero, 0x14($sp)
/* 17F190 802508B0 0C04993B */  jal       draw_msg
/* 17F194 802508B4 02263021 */   addu     $a2, $s1, $a2
/* 17F198 802508B8 080943A0 */  j         L80250E80_17F760
/* 17F19C 802508BC 00000000 */   nop
glabel L802508C0_17F1A0
/* 17F1A0 802508C0 86620012 */  lh        $v0, 0x12($s3)
/* 17F1A4 802508C4 00021080 */  sll       $v0, $v0, 2
/* 17F1A8 802508C8 3C108028 */  lui       $s0, %hi(bMessages)
/* 17F1AC 802508CC 02028021 */  addu      $s0, $s0, $v0
/* 17F1B0 802508D0 8E103770 */  lw        $s0, %lo(bMessages)($s0)
/* 17F1B4 802508D4 0C04992C */  jal       get_msg_lines
/* 17F1B8 802508D8 0200202D */   daddu    $a0, $s0, $zero
/* 17F1BC 802508DC 2443FFFF */  addiu     $v1, $v0, -1
/* 17F1C0 802508E0 0000282D */  daddu     $a1, $zero, $zero
/* 17F1C4 802508E4 00031040 */  sll       $v0, $v1, 1
/* 17F1C8 802508E8 3C018028 */  lui       $at, %hi(D_802835D4)
/* 17F1CC 802508EC 00220821 */  addu      $at, $at, $v0
/* 17F1D0 802508F0 842235D4 */  lh        $v0, %lo(D_802835D4)($at)
/* 17F1D4 802508F4 3C04802A */  lui       $a0, %hi(D_8029F640)
/* 17F1D8 802508F8 8484F640 */  lh        $a0, %lo(D_8029F640)($a0)
/* 17F1DC 802508FC 0C0496FA */  jal       set_message_value
/* 17F1E0 80250900 02228821 */   addu     $s1, $s1, $v0
/* 17F1E4 80250904 08094259 */  j         .L80250964
/* 17F1E8 80250908 0200202D */   daddu    $a0, $s0, $zero
glabel L8025090C_17F1EC
/* 17F1EC 8025090C 86620012 */  lh        $v0, 0x12($s3)
/* 17F1F0 80250910 00021080 */  sll       $v0, $v0, 2
/* 17F1F4 80250914 3C108028 */  lui       $s0, %hi(bMessages)
/* 17F1F8 80250918 02028021 */  addu      $s0, $s0, $v0
/* 17F1FC 8025091C 8E103770 */  lw        $s0, %lo(bMessages)($s0)
/* 17F200 80250920 0C04992C */  jal       get_msg_lines
/* 17F204 80250924 0200202D */   daddu    $a0, $s0, $zero
/* 17F208 80250928 2443FFFF */  addiu     $v1, $v0, -1
/* 17F20C 8025092C 0000282D */  daddu     $a1, $zero, $zero
/* 17F210 80250930 00031840 */  sll       $v1, $v1, 1
/* 17F214 80250934 3C02802A */  lui       $v0, %hi(D_8029F640)
/* 17F218 80250938 8442F640 */  lh        $v0, %lo(D_8029F640)($v0)
/* 17F21C 8025093C 3C018028 */  lui       $at, %hi(D_802835D4)
/* 17F220 80250940 00230821 */  addu      $at, $at, $v1
/* 17F224 80250944 842335D4 */  lh        $v1, %lo(D_802835D4)($at)
/* 17F228 80250948 00021080 */  sll       $v0, $v0, 2
/* 17F22C 8025094C 3C048028 */  lui       $a0, %hi(bActorMessages)
/* 17F230 80250950 00822021 */  addu      $a0, $a0, $v0
/* 17F234 80250954 8C8438C4 */  lw        $a0, %lo(bActorMessages)($a0)
/* 17F238 80250958 0C0496CF */  jal       set_message_msg
/* 17F23C 8025095C 02238821 */   addu     $s1, $s1, $v1
/* 17F240 80250960 0200202D */  daddu     $a0, $s0, $zero
.L80250964:
/* 17F244 80250964 0240282D */  daddu     $a1, $s2, $zero
/* 17F248 80250968 0220302D */  daddu     $a2, $s1, $zero
/* 17F24C 8025096C 240700FF */  addiu     $a3, $zero, 0xff
/* 17F250 80250970 2402000F */  addiu     $v0, $zero, 0xf
/* 17F254 80250974 AFA20010 */  sw        $v0, 0x10($sp)
/* 17F258 80250978 0C04993B */  jal       draw_msg
/* 17F25C 8025097C AFA00014 */   sw       $zero, 0x14($sp)
/* 17F260 80250980 080943A0 */  j         L80250E80_17F760
/* 17F264 80250984 00000000 */   nop
glabel L80250988_17F268
/* 17F268 80250988 2645001D */  addiu     $a1, $s2, 0x1d
/* 17F26C 8025098C 26260006 */  addiu     $a2, $s1, 6
/* 17F270 80250990 86620012 */  lh        $v0, 0x12($s3)
/* 17F274 80250994 240700FF */  addiu     $a3, $zero, 0xff
/* 17F278 80250998 00021080 */  sll       $v0, $v0, 2
/* 17F27C 8025099C 3C108028 */  lui       $s0, %hi(bMessages)
/* 17F280 802509A0 02028021 */  addu      $s0, $s0, $v0
/* 17F284 802509A4 8E103770 */  lw        $s0, %lo(bMessages)($s0)
/* 17F288 802509A8 2402000F */  addiu     $v0, $zero, 0xf
/* 17F28C 802509AC AFA20010 */  sw        $v0, 0x10($sp)
/* 17F290 802509B0 AFA00014 */  sw        $zero, 0x14($sp)
/* 17F294 802509B4 0C04993B */  jal       draw_msg
/* 17F298 802509B8 0200202D */   daddu    $a0, $s0, $zero
/* 17F29C 802509BC 2645000D */  addiu     $a1, $s2, 0xd
/* 17F2A0 802509C0 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F2A4 802509C4 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F2A8 802509C8 86040000 */  lh        $a0, ($s0)
/* 17F2AC 802509CC 0C051261 */  jal       set_hud_element_render_pos
/* 17F2B0 802509D0 2626000E */   addiu    $a2, $s1, 0xe
/* 17F2B4 802509D4 0809439D */  j         .L80250E74
/* 17F2B8 802509D8 00000000 */   nop
glabel L802509DC_17F2BC
/* 17F2BC 802509DC 82620016 */  lb        $v0, 0x16($s3)
/* 17F2C0 802509E0 28420002 */  slti      $v0, $v0, 2
/* 17F2C4 802509E4 10400002 */  beqz      $v0, .L802509F0
/* 17F2C8 802509E8 241400FF */   addiu    $s4, $zero, 0xff
/* 17F2CC 802509EC 241400A0 */  addiu     $s4, $zero, 0xa0
.L802509F0:
/* 17F2D0 802509F0 86630012 */  lh        $v1, 0x12($s3)
/* 17F2D4 802509F4 2402003B */  addiu     $v0, $zero, 0x3b
/* 17F2D8 802509F8 50620001 */  beql      $v1, $v0, .L80250A00
/* 17F2DC 802509FC 241400FF */   addiu    $s4, $zero, 0xff
.L80250A00:
/* 17F2E0 80250A00 2652FFF5 */  addiu     $s2, $s2, -0xb
/* 17F2E4 80250A04 00031080 */  sll       $v0, $v1, 2
/* 17F2E8 80250A08 3C108028 */  lui       $s0, %hi(bMessages)
/* 17F2EC 80250A0C 02028021 */  addu      $s0, $s0, $v0
/* 17F2F0 80250A10 8E103770 */  lw        $s0, %lo(bMessages)($s0)
/* 17F2F4 80250A14 2631FFFA */  addiu     $s1, $s1, -6
/* 17F2F8 80250A18 0C04992C */  jal       get_msg_lines
/* 17F2FC 80250A1C 0200202D */   daddu    $a0, $s0, $zero
/* 17F300 80250A20 2443FFFF */  addiu     $v1, $v0, -1
/* 17F304 80250A24 0200202D */  daddu     $a0, $s0, $zero
/* 17F308 80250A28 2645000B */  addiu     $a1, $s2, 0xb
/* 17F30C 80250A2C 0280382D */  daddu     $a3, $s4, $zero
/* 17F310 80250A30 00031040 */  sll       $v0, $v1, 1
/* 17F314 80250A34 3C038028 */  lui       $v1, %hi(D_802835D4)
/* 17F318 80250A38 00621821 */  addu      $v1, $v1, $v0
/* 17F31C 80250A3C 846335D4 */  lh        $v1, %lo(D_802835D4)($v1)
/* 17F320 80250A40 2402000F */  addiu     $v0, $zero, 0xf
/* 17F324 80250A44 AFA20010 */  sw        $v0, 0x10($sp)
/* 17F328 80250A48 AFA00014 */  sw        $zero, 0x14($sp)
/* 17F32C 80250A4C 02238821 */  addu      $s1, $s1, $v1
/* 17F330 80250A50 0C04993B */  jal       draw_msg
/* 17F334 80250A54 26260006 */   addiu    $a2, $s1, 6
/* 17F338 80250A58 96620012 */  lhu       $v0, 0x12($s3)
/* 17F33C 80250A5C 2442FFD2 */  addiu     $v0, $v0, -0x2e
/* 17F340 80250A60 00021400 */  sll       $v0, $v0, 0x10
/* 17F344 80250A64 00021C03 */  sra       $v1, $v0, 0x10
/* 17F348 80250A68 2C620014 */  sltiu     $v0, $v1, 0x14
/* 17F34C 80250A6C 10400104 */  beqz      $v0, L80250E80_17F760
/* 17F350 80250A70 00031080 */   sll      $v0, $v1, 2
/* 17F354 80250A74 3C01802A */  lui       $at, %hi(jtbl_8029D1A0)
/* 17F358 80250A78 00220821 */  addu      $at, $at, $v0
/* 17F35C 80250A7C 8C22D1A0 */  lw        $v0, %lo(jtbl_8029D1A0)($at)
/* 17F360 80250A80 00400008 */  jr        $v0
/* 17F364 80250A84 00000000 */   nop
glabel L80250A88_17F368
/* 17F368 80250A88 26450041 */  addiu     $a1, $s2, 0x41
/* 17F36C 80250A8C 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F370 80250A90 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F374 80250A94 86040000 */  lh        $a0, ($s0)
/* 17F378 80250A98 08094394 */  j         .L80250E50
/* 17F37C 80250A9C 2626000E */   addiu    $a2, $s1, 0xe
glabel L80250AA0_17F380
/* 17F380 80250AA0 26450037 */  addiu     $a1, $s2, 0x37
/* 17F384 80250AA4 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F388 80250AA8 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F38C 80250AAC 86040000 */  lh        $a0, ($s0)
/* 17F390 80250AB0 0C051261 */  jal       set_hud_element_render_pos
/* 17F394 80250AB4 2626000E */   addiu    $a2, $s1, 0xe
/* 17F398 80250AB8 86040000 */  lh        $a0, ($s0)
/* 17F39C 80250ABC 3C053F19 */  lui       $a1, 0x3f19
/* 17F3A0 80250AC0 0C051308 */  jal       set_hud_element_scale
/* 17F3A4 80250AC4 34A5999A */   ori      $a1, $a1, 0x999a
/* 17F3A8 80250AC8 86040000 */  lh        $a0, ($s0)
/* 17F3AC 80250ACC 0C0513AC */  jal       set_hud_element_alpha
/* 17F3B0 80250AD0 0280282D */   daddu    $a1, $s4, $zero
/* 17F3B4 80250AD4 86040000 */  lh        $a0, ($s0)
/* 17F3B8 80250AD8 0C0511EA */  jal       draw_hud_element_clipped
/* 17F3BC 80250ADC 00000000 */   nop
/* 17F3C0 80250AE0 26450049 */  addiu     $a1, $s2, 0x49
/* 17F3C4 80250AE4 3C10802A */  lui       $s0, %hi(D_8029F644)
/* 17F3C8 80250AE8 2610F644 */  addiu     $s0, $s0, %lo(D_8029F644)
/* 17F3CC 80250AEC 86040000 */  lh        $a0, ($s0)
/* 17F3D0 80250AF0 0C051261 */  jal       set_hud_element_render_pos
/* 17F3D4 80250AF4 2626001F */   addiu    $a2, $s1, 0x1f
/* 17F3D8 80250AF8 0809439A */  j         .L80250E68
/* 17F3DC 80250AFC 00000000 */   nop
glabel L80250B00_17F3E0
/* 17F3E0 80250B00 26450040 */  addiu     $a1, $s2, 0x40
/* 17F3E4 80250B04 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F3E8 80250B08 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F3EC 80250B0C 86040000 */  lh        $a0, ($s0)
/* 17F3F0 80250B10 08094394 */  j         .L80250E50
/* 17F3F4 80250B14 2626000E */   addiu    $a2, $s1, 0xe
glabel L80250B18_17F3F8
/* 17F3F8 80250B18 26450043 */  addiu     $a1, $s2, 0x43
/* 17F3FC 80250B1C 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F400 80250B20 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F404 80250B24 86040000 */  lh        $a0, ($s0)
/* 17F408 80250B28 08094394 */  j         .L80250E50
/* 17F40C 80250B2C 2626000E */   addiu    $a2, $s1, 0xe
glabel L80250B30_17F410
/* 17F410 80250B30 26450038 */  addiu     $a1, $s2, 0x38
/* 17F414 80250B34 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F418 80250B38 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F41C 80250B3C 86040000 */  lh        $a0, ($s0)
/* 17F420 80250B40 0C051261 */  jal       set_hud_element_render_pos
/* 17F424 80250B44 2626000E */   addiu    $a2, $s1, 0xe
/* 17F428 80250B48 86040000 */  lh        $a0, ($s0)
/* 17F42C 80250B4C 3C053F19 */  lui       $a1, 0x3f19
/* 17F430 80250B50 08094398 */  j         .L80250E60
/* 17F434 80250B54 34A5999A */   ori      $a1, $a1, 0x999a
glabel L80250B58_17F438
/* 17F438 80250B58 26450041 */  addiu     $a1, $s2, 0x41
/* 17F43C 80250B5C 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F440 80250B60 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F444 80250B64 86040000 */  lh        $a0, ($s0)
/* 17F448 80250B68 0C051261 */  jal       set_hud_element_render_pos
/* 17F44C 80250B6C 2626000D */   addiu    $a2, $s1, 0xd
/* 17F450 80250B70 86040000 */  lh        $a0, ($s0)
/* 17F454 80250B74 3C053F19 */  lui       $a1, 0x3f19
/* 17F458 80250B78 0C051308 */  jal       set_hud_element_scale
/* 17F45C 80250B7C 34A5999A */   ori      $a1, $a1, 0x999a
/* 17F460 80250B80 86040000 */  lh        $a0, ($s0)
/* 17F464 80250B84 0C0513AC */  jal       set_hud_element_alpha
/* 17F468 80250B88 0280282D */   daddu    $a1, $s4, $zero
/* 17F46C 80250B8C 86040000 */  lh        $a0, ($s0)
/* 17F470 80250B90 0C0511EA */  jal       draw_hud_element_clipped
/* 17F474 80250B94 00000000 */   nop
/* 17F478 80250B98 26450092 */  addiu     $a1, $s2, 0x92
/* 17F47C 80250B9C 3C10802A */  lui       $s0, %hi(D_8029F644)
/* 17F480 80250BA0 2610F644 */  addiu     $s0, $s0, %lo(D_8029F644)
/* 17F484 80250BA4 86040000 */  lh        $a0, ($s0)
/* 17F488 80250BA8 08094381 */  j         .L80250E04
/* 17F48C 80250BAC 26260020 */   addiu    $a2, $s1, 0x20
glabel L80250BB0_17F490
/* 17F490 80250BB0 26450056 */  addiu     $a1, $s2, 0x56
/* 17F494 80250BB4 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F498 80250BB8 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F49C 80250BBC 2631000D */  addiu     $s1, $s1, 0xd
/* 17F4A0 80250BC0 86040000 */  lh        $a0, ($s0)
/* 17F4A4 80250BC4 0C051261 */  jal       set_hud_element_render_pos
/* 17F4A8 80250BC8 0220302D */   daddu    $a2, $s1, $zero
/* 17F4AC 80250BCC 3C013F00 */  lui       $at, 0x3f00
/* 17F4B0 80250BD0 4481A000 */  mtc1      $at, $f20
/* 17F4B4 80250BD4 86040000 */  lh        $a0, ($s0)
/* 17F4B8 80250BD8 4405A000 */  mfc1      $a1, $f20
/* 17F4BC 80250BDC 0C051308 */  jal       set_hud_element_scale
/* 17F4C0 80250BE0 00000000 */   nop
/* 17F4C4 80250BE4 86040000 */  lh        $a0, ($s0)
/* 17F4C8 80250BE8 0C0513AC */  jal       set_hud_element_alpha
/* 17F4CC 80250BEC 0280282D */   daddu    $a1, $s4, $zero
/* 17F4D0 80250BF0 86040000 */  lh        $a0, ($s0)
/* 17F4D4 80250BF4 0C0511EA */  jal       draw_hud_element_clipped
/* 17F4D8 80250BF8 00000000 */   nop
/* 17F4DC 80250BFC 26450040 */  addiu     $a1, $s2, 0x40
/* 17F4E0 80250C00 3C10802A */  lui       $s0, %hi(D_8029F644)
/* 17F4E4 80250C04 2610F644 */  addiu     $s0, $s0, %lo(D_8029F644)
/* 17F4E8 80250C08 86040000 */  lh        $a0, ($s0)
/* 17F4EC 80250C0C 0C051261 */  jal       set_hud_element_render_pos
/* 17F4F0 80250C10 0220302D */   daddu    $a2, $s1, $zero
/* 17F4F4 80250C14 86040000 */  lh        $a0, ($s0)
/* 17F4F8 80250C18 4405A000 */  mfc1      $a1, $f20
/* 17F4FC 80250C1C 0C051308 */  jal       set_hud_element_scale
/* 17F500 80250C20 00000000 */   nop
/* 17F504 80250C24 86040000 */  lh        $a0, ($s0)
/* 17F508 80250C28 0C0513AC */  jal       set_hud_element_alpha
/* 17F50C 80250C2C 0280282D */   daddu    $a1, $s4, $zero
/* 17F510 80250C30 86040000 */  lh        $a0, ($s0)
/* 17F514 80250C34 0C0511EA */  jal       draw_hud_element_clipped
/* 17F518 80250C38 00000000 */   nop
/* 17F51C 80250C3C 2645006C */  addiu     $a1, $s2, 0x6c
/* 17F520 80250C40 3C10802A */  lui       $s0, %hi(D_8029F646)
/* 17F524 80250C44 2610F646 */  addiu     $s0, $s0, %lo(D_8029F646)
/* 17F528 80250C48 86040000 */  lh        $a0, ($s0)
/* 17F52C 80250C4C 08094394 */  j         .L80250E50
/* 17F530 80250C50 0220302D */   daddu    $a2, $s1, $zero
glabel L80250C54_17F534
/* 17F534 80250C54 26450069 */  addiu     $a1, $s2, 0x69
/* 17F538 80250C58 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F53C 80250C5C 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F540 80250C60 86040000 */  lh        $a0, ($s0)
/* 17F544 80250C64 0C051261 */  jal       set_hud_element_render_pos
/* 17F548 80250C68 2626000D */   addiu    $a2, $s1, 0xd
/* 17F54C 80250C6C 86040000 */  lh        $a0, ($s0)
/* 17F550 80250C70 0C0513AC */  jal       set_hud_element_alpha
/* 17F554 80250C74 0280282D */   daddu    $a1, $s4, $zero
/* 17F558 80250C78 86040000 */  lh        $a0, ($s0)
/* 17F55C 80250C7C 0C0511EA */  jal       draw_hud_element_clipped
/* 17F560 80250C80 00000000 */   nop
/* 17F564 80250C84 26450041 */  addiu     $a1, $s2, 0x41
/* 17F568 80250C88 3C10802A */  lui       $s0, %hi(D_8029F644)
/* 17F56C 80250C8C 2610F644 */  addiu     $s0, $s0, %lo(D_8029F644)
/* 17F570 80250C90 86040000 */  lh        $a0, ($s0)
/* 17F574 80250C94 08094394 */  j         .L80250E50
/* 17F578 80250C98 2626000E */   addiu    $a2, $s1, 0xe
glabel L80250C9C_17F57C
/* 17F57C 80250C9C 2645003F */  addiu     $a1, $s2, 0x3f
/* 17F580 80250CA0 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F584 80250CA4 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F588 80250CA8 2631000E */  addiu     $s1, $s1, 0xe
/* 17F58C 80250CAC 86040000 */  lh        $a0, ($s0)
/* 17F590 80250CB0 0C051261 */  jal       set_hud_element_render_pos
/* 17F594 80250CB4 0220302D */   daddu    $a2, $s1, $zero
/* 17F598 80250CB8 3C013F00 */  lui       $at, 0x3f00
/* 17F59C 80250CBC 4481A000 */  mtc1      $at, $f20
/* 17F5A0 80250CC0 86040000 */  lh        $a0, ($s0)
/* 17F5A4 80250CC4 4405A000 */  mfc1      $a1, $f20
/* 17F5A8 80250CC8 0C051308 */  jal       set_hud_element_scale
/* 17F5AC 80250CCC 00000000 */   nop
/* 17F5B0 80250CD0 86040000 */  lh        $a0, ($s0)
/* 17F5B4 80250CD4 0C0513AC */  jal       set_hud_element_alpha
/* 17F5B8 80250CD8 0280282D */   daddu    $a1, $s4, $zero
/* 17F5BC 80250CDC 86040000 */  lh        $a0, ($s0)
/* 17F5C0 80250CE0 0C0511EA */  jal       draw_hud_element_clipped
/* 17F5C4 80250CE4 00000000 */   nop
/* 17F5C8 80250CE8 26450054 */  addiu     $a1, $s2, 0x54
/* 17F5CC 80250CEC 3C10802A */  lui       $s0, %hi(D_8029F644)
/* 17F5D0 80250CF0 2610F644 */  addiu     $s0, $s0, %lo(D_8029F644)
/* 17F5D4 80250CF4 86040000 */  lh        $a0, ($s0)
/* 17F5D8 80250CF8 08094394 */  j         .L80250E50
/* 17F5DC 80250CFC 0220302D */   daddu    $a2, $s1, $zero
glabel L80250D00_17F5E0
/* 17F5E0 80250D00 2645007C */  addiu     $a1, $s2, 0x7c
/* 17F5E4 80250D04 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F5E8 80250D08 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F5EC 80250D0C 86040000 */  lh        $a0, ($s0)
/* 17F5F0 80250D10 08094394 */  j         .L80250E50
/* 17F5F4 80250D14 2626000E */   addiu    $a2, $s1, 0xe
glabel L80250D18_17F5F8
/* 17F5F8 80250D18 26450038 */  addiu     $a1, $s2, 0x38
/* 17F5FC 80250D1C 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F600 80250D20 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F604 80250D24 86040000 */  lh        $a0, ($s0)
/* 17F608 80250D28 0C051261 */  jal       set_hud_element_render_pos
/* 17F60C 80250D2C 2626001F */   addiu    $a2, $s1, 0x1f
/* 17F610 80250D30 86040000 */  lh        $a0, ($s0)
/* 17F614 80250D34 0C0513AC */  jal       set_hud_element_alpha
/* 17F618 80250D38 0280282D */   daddu    $a1, $s4, $zero
/* 17F61C 80250D3C 86040000 */  lh        $a0, ($s0)
/* 17F620 80250D40 0C0511EA */  jal       draw_hud_element_clipped
/* 17F624 80250D44 00000000 */   nop
/* 17F628 80250D48 26450035 */  addiu     $a1, $s2, 0x35
/* 17F62C 80250D4C 3C10802A */  lui       $s0, %hi(D_8029F644)
/* 17F630 80250D50 2610F644 */  addiu     $s0, $s0, %lo(D_8029F644)
/* 17F634 80250D54 86040000 */  lh        $a0, ($s0)
/* 17F638 80250D58 08094394 */  j         .L80250E50
/* 17F63C 80250D5C 2626000E */   addiu    $a2, $s1, 0xe
glabel L80250D60_17F640
/* 17F640 80250D60 2645006B */  addiu     $a1, $s2, 0x6b
/* 17F644 80250D64 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F648 80250D68 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F64C 80250D6C 86040000 */  lh        $a0, ($s0)
/* 17F650 80250D70 0C051261 */  jal       set_hud_element_render_pos
/* 17F654 80250D74 2626000D */   addiu    $a2, $s1, 0xd
/* 17F658 80250D78 86040000 */  lh        $a0, ($s0)
/* 17F65C 80250D7C 3C053F19 */  lui       $a1, 0x3f19
/* 17F660 80250D80 34A5999A */  ori       $a1, $a1, 0x999a
/* 17F664 80250D84 0C051308 */  jal       set_hud_element_scale
/* 17F668 80250D88 2631000F */   addiu    $s1, $s1, 0xf
/* 17F66C 80250D8C 86040000 */  lh        $a0, ($s0)
/* 17F670 80250D90 0C0513AC */  jal       set_hud_element_alpha
/* 17F674 80250D94 0280282D */   daddu    $a1, $s4, $zero
/* 17F678 80250D98 86040000 */  lh        $a0, ($s0)
/* 17F67C 80250D9C 0C0511EA */  jal       draw_hud_element_clipped
/* 17F680 80250DA0 00000000 */   nop
/* 17F684 80250DA4 264500D2 */  addiu     $a1, $s2, 0xd2
/* 17F688 80250DA8 3C10802A */  lui       $s0, %hi(D_8029F644)
/* 17F68C 80250DAC 2610F644 */  addiu     $s0, $s0, %lo(D_8029F644)
/* 17F690 80250DB0 86040000 */  lh        $a0, ($s0)
/* 17F694 80250DB4 0C051261 */  jal       set_hud_element_render_pos
/* 17F698 80250DB8 0220302D */   daddu    $a2, $s1, $zero
/* 17F69C 80250DBC 3C013F4C */  lui       $at, 0x3f4c
/* 17F6A0 80250DC0 3421CCCD */  ori       $at, $at, 0xcccd
/* 17F6A4 80250DC4 4481A000 */  mtc1      $at, $f20
/* 17F6A8 80250DC8 86040000 */  lh        $a0, ($s0)
/* 17F6AC 80250DCC 4405A000 */  mfc1      $a1, $f20
/* 17F6B0 80250DD0 0C051308 */  jal       set_hud_element_scale
/* 17F6B4 80250DD4 00000000 */   nop
/* 17F6B8 80250DD8 86040000 */  lh        $a0, ($s0)
/* 17F6BC 80250DDC 0C0513AC */  jal       set_hud_element_alpha
/* 17F6C0 80250DE0 0280282D */   daddu    $a1, $s4, $zero
/* 17F6C4 80250DE4 86040000 */  lh        $a0, ($s0)
/* 17F6C8 80250DE8 0C051086 */  jal       func_80144218
/* 17F6CC 80250DEC 00000000 */   nop
/* 17F6D0 80250DF0 26450038 */  addiu     $a1, $s2, 0x38
/* 17F6D4 80250DF4 3C10802A */  lui       $s0, %hi(D_8029F646)
/* 17F6D8 80250DF8 2610F646 */  addiu     $s0, $s0, %lo(D_8029F646)
/* 17F6DC 80250DFC 86040000 */  lh        $a0, ($s0)
/* 17F6E0 80250E00 0220302D */  daddu     $a2, $s1, $zero
.L80250E04:
/* 17F6E4 80250E04 0C051261 */  jal       set_hud_element_render_pos
/* 17F6E8 80250E08 00000000 */   nop
/* 17F6EC 80250E0C 86040000 */  lh        $a0, ($s0)
/* 17F6F0 80250E10 3C053F4C */  lui       $a1, 0x3f4c
/* 17F6F4 80250E14 0C051308 */  jal       set_hud_element_scale
/* 17F6F8 80250E18 34A5CCCD */   ori      $a1, $a1, 0xcccd
/* 17F6FC 80250E1C 86040000 */  lh        $a0, ($s0)
/* 17F700 80250E20 0C0513AC */  jal       set_hud_element_alpha
/* 17F704 80250E24 0280282D */   daddu    $a1, $s4, $zero
/* 17F708 80250E28 86040000 */  lh        $a0, ($s0)
/* 17F70C 80250E2C 0C051086 */  jal       func_80144218
/* 17F710 80250E30 00000000 */   nop
/* 17F714 80250E34 080943A0 */  j         L80250E80_17F760
/* 17F718 80250E38 00000000 */   nop
glabel L80250E3C_17F71C
/* 17F71C 80250E3C 26450040 */  addiu     $a1, $s2, 0x40
/* 17F720 80250E40 3C10802A */  lui       $s0, %hi(D_8029F642)
/* 17F724 80250E44 2610F642 */  addiu     $s0, $s0, %lo(D_8029F642)
/* 17F728 80250E48 86040000 */  lh        $a0, ($s0)
/* 17F72C 80250E4C 2626000D */  addiu     $a2, $s1, 0xd
.L80250E50:
/* 17F730 80250E50 0C051261 */  jal       set_hud_element_render_pos
/* 17F734 80250E54 00000000 */   nop
/* 17F738 80250E58 86040000 */  lh        $a0, ($s0)
/* 17F73C 80250E5C 3C053F00 */  lui       $a1, 0x3f00
.L80250E60:
/* 17F740 80250E60 0C051308 */  jal       set_hud_element_scale
/* 17F744 80250E64 00000000 */   nop
.L80250E68:
/* 17F748 80250E68 86040000 */  lh        $a0, ($s0)
/* 17F74C 80250E6C 0C0513AC */  jal       set_hud_element_alpha
/* 17F750 80250E70 0280282D */   daddu    $a1, $s4, $zero
.L80250E74:
/* 17F754 80250E74 86040000 */  lh        $a0, ($s0)
/* 17F758 80250E78 0C0511EA */  jal       draw_hud_element_clipped
/* 17F75C 80250E7C 00000000 */   nop
glabel L80250E80_17F760
/* 17F760 80250E80 8FBF002C */  lw        $ra, 0x2c($sp)
/* 17F764 80250E84 8FB40028 */  lw        $s4, 0x28($sp)
/* 17F768 80250E88 8FB30024 */  lw        $s3, 0x24($sp)
/* 17F76C 80250E8C 8FB20020 */  lw        $s2, 0x20($sp)
/* 17F770 80250E90 8FB1001C */  lw        $s1, 0x1c($sp)
/* 17F774 80250E94 8FB00018 */  lw        $s0, 0x18($sp)
/* 17F778 80250E98 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 17F77C 80250E9C 03E00008 */  jr        $ra
/* 17F780 80250EA0 27BD0038 */   addiu    $sp, $sp, 0x38
