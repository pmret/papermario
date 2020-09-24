.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_entity_transform_matrix
/* A692C 8011022C 27BDFE00 */  addiu     $sp, $sp, -0x200
/* A6930 80110230 AFB401E8 */  sw        $s4, 0x1e8($sp)
/* A6934 80110234 0080A02D */  daddu     $s4, $a0, $zero
/* A6938 80110238 AFBF01EC */  sw        $ra, 0x1ec($sp)
/* A693C 8011023C AFB301E4 */  sw        $s3, 0x1e4($sp)
/* A6940 80110240 AFB201E0 */  sw        $s2, 0x1e0($sp)
/* A6944 80110244 AFB101DC */  sw        $s1, 0x1dc($sp)
/* A6948 80110248 AFB001D8 */  sw        $s0, 0x1d8($sp)
/* A694C 8011024C F7B601F8 */  sdc1      $f22, 0x1f8($sp)
/* A6950 80110250 F7B401F0 */  sdc1      $f20, 0x1f0($sp)
/* A6954 80110254 8E820020 */  lw        $v0, 0x20($s4)
/* A6958 80110258 10400005 */  beqz      $v0, .L80110270
/* A695C 8011025C 27B30058 */   addiu    $s3, $sp, 0x58
/* A6960 80110260 0040F809 */  jalr      $v0
/* A6964 80110264 00000000 */   nop      
/* A6968 80110268 080440D3 */  j         .L8011034C
/* A696C 8011026C 00000000 */   nop      
.L80110270:
/* A6970 80110270 8E850048 */  lw        $a1, 0x48($s4)
/* A6974 80110274 8E86004C */  lw        $a2, 0x4c($s4)
/* A6978 80110278 8E870050 */  lw        $a3, 0x50($s4)
/* A697C 8011027C 4480A000 */  mtc1      $zero, $f20
/* A6980 80110280 0C019E40 */  jal       guTranslateF
/* A6984 80110284 0260202D */   daddu    $a0, $s3, $zero
/* A6988 80110288 3C013F80 */  lui       $at, 0x3f80
/* A698C 8011028C 4481B000 */  mtc1      $at, $f22
/* A6990 80110290 27B200D8 */  addiu     $s2, $sp, 0xd8
/* A6994 80110294 E7B40010 */  swc1      $f20, 0x10($sp)
/* A6998 80110298 8E850060 */  lw        $a1, 0x60($s4)
/* A699C 8011029C 4407A000 */  mfc1      $a3, $f20
/* A69A0 801102A0 4406B000 */  mfc1      $a2, $f22
/* A69A4 801102A4 0C019EC8 */  jal       guRotateF
/* A69A8 801102A8 0240202D */   daddu    $a0, $s2, $zero
/* A69AC 801102AC 27B10118 */  addiu     $s1, $sp, 0x118
/* A69B0 801102B0 E7B40010 */  swc1      $f20, 0x10($sp)
/* A69B4 801102B4 8E850064 */  lw        $a1, 0x64($s4)
/* A69B8 801102B8 4406A000 */  mfc1      $a2, $f20
/* A69BC 801102BC 4407B000 */  mfc1      $a3, $f22
/* A69C0 801102C0 0C019EC8 */  jal       guRotateF
/* A69C4 801102C4 0220202D */   daddu    $a0, $s1, $zero
/* A69C8 801102C8 27B00158 */  addiu     $s0, $sp, 0x158
/* A69CC 801102CC 4406A000 */  mfc1      $a2, $f20
/* A69D0 801102D0 0200202D */  daddu     $a0, $s0, $zero
/* A69D4 801102D4 E7B60010 */  swc1      $f22, 0x10($sp)
/* A69D8 801102D8 8E850068 */  lw        $a1, 0x68($s4)
/* A69DC 801102DC 0C019EC8 */  jal       guRotateF
/* A69E0 801102E0 00C0382D */   daddu    $a3, $a2, $zero
/* A69E4 801102E4 0200202D */  daddu     $a0, $s0, $zero
/* A69E8 801102E8 0240282D */  daddu     $a1, $s2, $zero
/* A69EC 801102EC 0C019D80 */  jal       guMtxCatF
/* A69F0 801102F0 27A60018 */   addiu    $a2, $sp, 0x18
/* A69F4 801102F4 27A40018 */  addiu     $a0, $sp, 0x18
/* A69F8 801102F8 0220282D */  daddu     $a1, $s1, $zero
/* A69FC 801102FC 27B10098 */  addiu     $s1, $sp, 0x98
/* A6A00 80110300 0C019D80 */  jal       guMtxCatF
/* A6A04 80110304 0220302D */   daddu    $a2, $s1, $zero
/* A6A08 80110308 27B00198 */  addiu     $s0, $sp, 0x198
/* A6A0C 8011030C 8E850054 */  lw        $a1, 0x54($s4)
/* A6A10 80110310 8E860058 */  lw        $a2, 0x58($s4)
/* A6A14 80110314 8E87005C */  lw        $a3, 0x5c($s4)
/* A6A18 80110318 0C019DF0 */  jal       guScaleF
/* A6A1C 8011031C 0200202D */   daddu    $a0, $s0, $zero
/* A6A20 80110320 0200202D */  daddu     $a0, $s0, $zero
/* A6A24 80110324 0220282D */  daddu     $a1, $s1, $zero
/* A6A28 80110328 0C019D80 */  jal       guMtxCatF
/* A6A2C 8011032C 27A60018 */   addiu    $a2, $sp, 0x18
/* A6A30 80110330 27A40018 */  addiu     $a0, $sp, 0x18
/* A6A34 80110334 0260282D */  daddu     $a1, $s3, $zero
/* A6A38 80110338 0C019D80 */  jal       guMtxCatF
/* A6A3C 8011033C 0220302D */   daddu    $a2, $s1, $zero
/* A6A40 80110340 0220202D */  daddu     $a0, $s1, $zero
/* A6A44 80110344 0C019D40 */  jal       guMtxF2L
/* A6A48 80110348 268500B8 */   addiu    $a1, $s4, 0xb8
.L8011034C:
/* A6A4C 8011034C 8FBF01EC */  lw        $ra, 0x1ec($sp)
/* A6A50 80110350 8FB401E8 */  lw        $s4, 0x1e8($sp)
/* A6A54 80110354 8FB301E4 */  lw        $s3, 0x1e4($sp)
/* A6A58 80110358 8FB201E0 */  lw        $s2, 0x1e0($sp)
/* A6A5C 8011035C 8FB101DC */  lw        $s1, 0x1dc($sp)
/* A6A60 80110360 8FB001D8 */  lw        $s0, 0x1d8($sp)
/* A6A64 80110364 D7B601F8 */  ldc1      $f22, 0x1f8($sp)
/* A6A68 80110368 D7B401F0 */  ldc1      $f20, 0x1f0($sp)
/* A6A6C 8011036C 03E00008 */  jr        $ra
/* A6A70 80110370 27BD0200 */   addiu    $sp, $sp, 0x200
