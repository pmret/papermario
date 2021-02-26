.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B13C
/* 1653C 8003B13C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 16540 8003B140 AFBF0010 */  sw        $ra, 0x10($sp)
/* 16544 8003B144 808300B4 */  lb        $v1, 0xb4($a0)
/* 16548 8003B148 2C620005 */  sltiu     $v0, $v1, 5
/* 1654C 8003B14C 10400019 */  beqz      $v0, .L8003B1B4
/* 16550 8003B150 00C0382D */   daddu    $a3, $a2, $zero
/* 16554 8003B154 00031080 */  sll       $v0, $v1, 2
/* 16558 8003B158 3C01800A */  lui       $at, %hi(D_800984A8)
/* 1655C 8003B15C 00220821 */  addu      $at, $at, $v0
/* 16560 8003B160 8C2284A8 */  lw        $v0, %lo(D_800984A8)($at)
/* 16564 8003B164 00400008 */  jr        $v0
/* 16568 8003B168 00000000 */   nop
/* 1656C 8003B16C 0C00EC70 */  jal       func_8003B1C0
/* 16570 8003B170 00E0302D */   daddu    $a2, $a3, $zero
/* 16574 8003B174 0800EC6D */  j         .L8003B1B4
/* 16578 8003B178 00000000 */   nop
/* 1657C 8003B17C 0C00EC9D */  jal       func_8003B274
/* 16580 8003B180 00E0302D */   daddu    $a2, $a3, $zero
/* 16584 8003B184 0800EC6D */  j         .L8003B1B4
/* 16588 8003B188 00000000 */   nop
/* 1658C 8003B18C 0C00EDC8 */  jal       func_8003B720
/* 16590 8003B190 0000302D */   daddu    $a2, $zero, $zero
/* 16594 8003B194 0800EC6D */  j         .L8003B1B4
/* 16598 8003B198 00000000 */   nop
/* 1659C 8003B19C 0C00EDC8 */  jal       func_8003B720
/* 165A0 8003B1A0 24060001 */   addiu    $a2, $zero, 1
/* 165A4 8003B1A4 0800EC6D */  j         .L8003B1B4
/* 165A8 8003B1A8 00000000 */   nop
/* 165AC 8003B1AC 0C00EEE6 */  jal       func_8003BB98
/* 165B0 8003B1B0 00E0302D */   daddu    $a2, $a3, $zero
.L8003B1B4:
/* 165B4 8003B1B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 165B8 8003B1B8 03E00008 */  jr        $ra
/* 165BC 8003B1BC 27BD0018 */   addiu    $sp, $sp, 0x18
