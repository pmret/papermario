.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel find_script_labels
/* E7AF8 802C3148 0000182D */  daddu     $v1, $zero, $zero
/* E7AFC 802C314C 2406FFFF */  addiu     $a2, $zero, -1
/* E7B00 802C3150 0080282D */  daddu     $a1, $a0, $zero
.L802C3154:
/* E7B04 802C3154 00831021 */  addu      $v0, $a0, $v1
/* E7B08 802C3158 A0460010 */  sb        $a2, 0x10($v0)
/* E7B0C 802C315C ACA00020 */  sw        $zero, 0x20($a1)
/* E7B10 802C3160 24630001 */  addiu     $v1, $v1, 1
/* E7B14 802C3164 28620010 */  slti      $v0, $v1, 0x10
/* E7B18 802C3168 1440FFFA */  bnez      $v0, .L802C3154
/* E7B1C 802C316C 24A50004 */   addiu    $a1, $a1, 4
/* E7B20 802C3170 0000382D */  daddu     $a3, $zero, $zero
/* E7B24 802C3174 8C830008 */  lw        $v1, 8($a0)
/* E7B28 802C3178 240A0001 */  addiu     $t2, $zero, 1
/* E7B2C 802C317C 24090003 */  addiu     $t1, $zero, 3
/* E7B30 802C3180 0080402D */  daddu     $t0, $a0, $zero
.L802C3184:
/* E7B34 802C3184 8C650000 */  lw        $a1, ($v1)
/* E7B38 802C3188 24630004 */  addiu     $v1, $v1, 4
/* E7B3C 802C318C 8C620000 */  lw        $v0, ($v1)
/* E7B40 802C3190 24630004 */  addiu     $v1, $v1, 4
/* E7B44 802C3194 8C660000 */  lw        $a2, ($v1)
/* E7B48 802C3198 00021080 */  sll       $v0, $v0, 2
/* E7B4C 802C319C 10AA000D */  beq       $a1, $t2, .L802C31D4
/* E7B50 802C31A0 00621821 */   addu     $v1, $v1, $v0
/* E7B54 802C31A4 14A90007 */  bne       $a1, $t1, .L802C31C4
/* E7B58 802C31A8 28E20010 */   slti     $v0, $a3, 0x10
/* E7B5C 802C31AC 00871021 */  addu      $v0, $a0, $a3
/* E7B60 802C31B0 A0460010 */  sb        $a2, 0x10($v0)
/* E7B64 802C31B4 AD030020 */  sw        $v1, 0x20($t0)
/* E7B68 802C31B8 25080004 */  addiu     $t0, $t0, 4
/* E7B6C 802C31BC 24E70001 */  addiu     $a3, $a3, 1
/* E7B70 802C31C0 28E20010 */  slti      $v0, $a3, 0x10
.L802C31C4:
/* E7B74 802C31C4 1440FFEF */  bnez      $v0, .L802C3184
/* E7B78 802C31C8 00000000 */   nop      
.L802C31CC:
/* E7B7C 802C31CC 080B0C73 */  j         .L802C31CC
/* E7B80 802C31D0 00000000 */   nop      
.L802C31D4:
/* E7B84 802C31D4 03E00008 */  jr        $ra
/* E7B88 802C31D8 00000000 */   nop      
