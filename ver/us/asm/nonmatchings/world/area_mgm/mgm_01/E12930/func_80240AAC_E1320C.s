.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AAC_E1320C
/* E1320C 80240AAC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E13210 80240AB0 AFB1001C */  sw        $s1, 0x1c($sp)
/* E13214 80240AB4 0080882D */  daddu     $s1, $a0, $zero
/* E13218 80240AB8 0000202D */  daddu     $a0, $zero, $zero
/* E1321C 80240ABC AFBF0020 */  sw        $ra, 0x20($sp)
/* E13220 80240AC0 0C00FB3A */  jal       get_enemy
/* E13224 80240AC4 AFB00018 */   sw       $s0, 0x18($sp)
/* E13228 80240AC8 8E23000C */  lw        $v1, 0xc($s1)
/* E1322C 80240ACC 8C650000 */  lw        $a1, ($v1)
/* E13230 80240AD0 8C500080 */  lw        $s0, 0x80($v0)
/* E13234 80240AD4 0C0B1EAF */  jal       evt_get_variable
/* E13238 80240AD8 0220202D */   daddu    $a0, $s1, $zero
/* E1323C 80240ADC 00021840 */  sll       $v1, $v0, 1
/* E13240 80240AE0 00621821 */  addu      $v1, $v1, $v0
/* E13244 80240AE4 000318C0 */  sll       $v1, $v1, 3
/* E13248 80240AE8 00621823 */  subu      $v1, $v1, $v0
/* E1324C 80240AEC 00031880 */  sll       $v1, $v1, 2
/* E13250 80240AF0 02038021 */  addu      $s0, $s0, $v1
/* E13254 80240AF4 8E02008C */  lw        $v0, 0x8c($s0)
/* E13258 80240AF8 8E030090 */  lw        $v1, 0x90($s0)
/* E1325C 80240AFC 24420001 */  addiu     $v0, $v0, 1
/* E13260 80240B00 AE02008C */  sw        $v0, 0x8c($s0)
/* E13264 80240B04 AFA30010 */  sw        $v1, 0x10($sp)
/* E13268 80240B08 8E0500A0 */  lw        $a1, 0xa0($s0)
/* E1326C 80240B0C 8E0600AC */  lw        $a2, 0xac($s0)
/* E13270 80240B10 8E07008C */  lw        $a3, 0x8c($s0)
/* E13274 80240B14 0C00A8ED */  jal       update_lerp
/* E13278 80240B18 24040004 */   addiu    $a0, $zero, 4
/* E1327C 80240B1C 8E020090 */  lw        $v0, 0x90($s0)
/* E13280 80240B20 E6000094 */  swc1      $f0, 0x94($s0)
/* E13284 80240B24 AFA20010 */  sw        $v0, 0x10($sp)
/* E13288 80240B28 8E0500A4 */  lw        $a1, 0xa4($s0)
/* E1328C 80240B2C 8E0600B0 */  lw        $a2, 0xb0($s0)
/* E13290 80240B30 8E07008C */  lw        $a3, 0x8c($s0)
/* E13294 80240B34 0C00A8ED */  jal       update_lerp
/* E13298 80240B38 24040004 */   addiu    $a0, $zero, 4
/* E1329C 80240B3C 8E020090 */  lw        $v0, 0x90($s0)
/* E132A0 80240B40 E6000098 */  swc1      $f0, 0x98($s0)
/* E132A4 80240B44 AFA20010 */  sw        $v0, 0x10($sp)
/* E132A8 80240B48 8E0500A8 */  lw        $a1, 0xa8($s0)
/* E132AC 80240B4C 8E0600B4 */  lw        $a2, 0xb4($s0)
/* E132B0 80240B50 8E07008C */  lw        $a3, 0x8c($s0)
/* E132B4 80240B54 0C00A8ED */  jal       update_lerp
/* E132B8 80240B58 0000202D */   daddu    $a0, $zero, $zero
/* E132BC 80240B5C 8E020090 */  lw        $v0, 0x90($s0)
/* E132C0 80240B60 E600009C */  swc1      $f0, 0x9c($s0)
/* E132C4 80240B64 AFA20010 */  sw        $v0, 0x10($sp)
/* E132C8 80240B68 8E0500BC */  lw        $a1, 0xbc($s0)
/* E132CC 80240B6C 8E0600C0 */  lw        $a2, 0xc0($s0)
/* E132D0 80240B70 8E07008C */  lw        $a3, 0x8c($s0)
/* E132D4 80240B74 0C00A8ED */  jal       update_lerp
/* E132D8 80240B78 0000202D */   daddu    $a0, $zero, $zero
/* E132DC 80240B7C 8E020090 */  lw        $v0, 0x90($s0)
/* E132E0 80240B80 E60000B8 */  swc1      $f0, 0xb8($s0)
/* E132E4 80240B84 AFA20010 */  sw        $v0, 0x10($sp)
/* E132E8 80240B88 8E0500C8 */  lw        $a1, 0xc8($s0)
/* E132EC 80240B8C 8E0600CC */  lw        $a2, 0xcc($s0)
/* E132F0 80240B90 8E07008C */  lw        $a3, 0x8c($s0)
/* E132F4 80240B94 0C00A8ED */  jal       update_lerp
/* E132F8 80240B98 0000202D */   daddu    $a0, $zero, $zero
/* E132FC 80240B9C 8E02008C */  lw        $v0, 0x8c($s0)
/* E13300 80240BA0 8E030090 */  lw        $v1, 0x90($s0)
/* E13304 80240BA4 0043102A */  slt       $v0, $v0, $v1
/* E13308 80240BA8 14400006 */  bnez      $v0, .L80240BC4
/* E1330C 80240BAC E60000C4 */   swc1     $f0, 0xc4($s0)
/* E13310 80240BB0 0220202D */  daddu     $a0, $s1, $zero
/* E13314 80240BB4 3C05FE36 */  lui       $a1, 0xfe36
/* E13318 80240BB8 34A53C83 */  ori       $a1, $a1, 0x3c83
/* E1331C 80240BBC 080902F5 */  j         .L80240BD4
/* E13320 80240BC0 24060001 */   addiu    $a2, $zero, 1
.L80240BC4:
/* E13324 80240BC4 0220202D */  daddu     $a0, $s1, $zero
/* E13328 80240BC8 3C05FE36 */  lui       $a1, 0xfe36
/* E1332C 80240BCC 34A53C83 */  ori       $a1, $a1, 0x3c83
/* E13330 80240BD0 0000302D */  daddu     $a2, $zero, $zero
.L80240BD4:
/* E13334 80240BD4 0C0B2026 */  jal       evt_set_variable
/* E13338 80240BD8 00000000 */   nop
/* E1333C 80240BDC 8FBF0020 */  lw        $ra, 0x20($sp)
/* E13340 80240BE0 8FB1001C */  lw        $s1, 0x1c($sp)
/* E13344 80240BE4 8FB00018 */  lw        $s0, 0x18($sp)
/* E13348 80240BE8 24020002 */  addiu     $v0, $zero, 2
/* E1334C 80240BEC 03E00008 */  jr        $ra
/* E13350 80240BF0 27BD0028 */   addiu    $sp, $sp, 0x28
