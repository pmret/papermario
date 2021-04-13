.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F164
/* 4A564 8006F164 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4A568 8006F168 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4A56C 8006F16C AFA40020 */  sw        $a0, 0x20($sp)
/* 4A570 8006F170 AFA50024 */  sw        $a1, 0x24($sp)
/* 4A574 8006F174 27A4001F */  addiu     $a0, $sp, 0x1f
/* 4A578 8006F178 0C01BC26 */  jal       func_8006F098
/* 4A57C 8006F17C 00000000 */   nop
/* 4A580 8006F180 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A584 8006F184 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A588 8006F188 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A58C 8006F18C 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A590 8006F190 3C010001 */  lui       $at, 1
/* 4A594 8006F194 00A17025 */  or        $t6, $a1, $at
/* 4A598 8006F198 01C02825 */  or        $a1, $t6, $zero
/* 4A59C 8006F19C 3C06E100 */  lui       $a2, 0xe100
/* 4A5A0 8006F1A0 0C01834C */  jal       osEPiWriteIo
/* 4A5A4 8006F1A4 00000000 */   nop
/* 4A5A8 8006F1A8 3C01800B */  lui       $at, %hi(D_800B0C22)
/* 4A5AC 8006F1AC A0200C22 */  sb        $zero, %lo(D_800B0C22)($at)
/* 4A5B0 8006F1B0 3C0F800B */  lui       $t7, %hi(D_800B0C38)
/* 4A5B4 8006F1B4 25EF0C38 */  addiu     $t7, $t7, %lo(D_800B0C38)
/* 4A5B8 8006F1B8 3C01800B */  lui       $at, %hi(D_800B0C24)
/* 4A5BC 8006F1BC AC2F0C24 */  sw        $t7, %lo(D_800B0C24)($at)
/* 4A5C0 8006F1C0 3C18800B */  lui       $t8, %hi(D_800B0C10)
/* 4A5C4 8006F1C4 27180C10 */  addiu     $t8, $t8, %lo(D_800B0C10)
/* 4A5C8 8006F1C8 3C01800B */  lui       $at, %hi(D_800B0C28)
/* 4A5CC 8006F1CC AC380C28 */  sw        $t8, %lo(D_800B0C28)($at)
/* 4A5D0 8006F1D0 3C01800B */  lui       $at, %hi(D_800B0C2C)
/* 4A5D4 8006F1D4 AC200C2C */  sw        $zero, %lo(D_800B0C2C)($at)
/* 4A5D8 8006F1D8 24190008 */  addiu     $t9, $zero, 8
/* 4A5DC 8006F1DC 3C01800B */  lui       $at, %hi(D_800B0C30)
/* 4A5E0 8006F1E0 AC390C30 */  sw        $t9, %lo(D_800B0C30)($at)
/* 4A5E4 8006F1E4 3C04800B */  lui       $a0, %hi(D_800B0C10)
/* 4A5E8 8006F1E8 24840C10 */  addiu     $a0, $a0, %lo(D_800B0C10)
/* 4A5EC 8006F1EC 24050010 */  addiu     $a1, $zero, 0x10
/* 4A5F0 8006F1F0 0C018608 */  jal       func_80061820
/* 4A5F4 8006F1F4 00000000 */   nop
/* 4A5F8 8006F1F8 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A5FC 8006F1FC 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A600 8006F200 3C05800B */  lui       $a1, %hi(D_800B0C20)
/* 4A604 8006F204 24A50C20 */  addiu     $a1, $a1, %lo(D_800B0C20)
/* 4A608 8006F208 00003025 */  or        $a2, $zero, $zero
/* 4A60C 8006F20C 0C01837C */  jal       func_80060DF0
/* 4A610 8006F210 00000000 */   nop
/* 4A614 8006F214 3C04800B */  lui       $a0, %hi(D_800B0C38)
/* 4A618 8006F218 24840C38 */  addiu     $a0, $a0, %lo(D_800B0C38)
/* 4A61C 8006F21C 00002825 */  or        $a1, $zero, $zero
/* 4A620 8006F220 24060001 */  addiu     $a2, $zero, 1
/* 4A624 8006F224 0C0195B0 */  jal       func_800656C0
/* 4A628 8006F228 00000000 */   nop
/* 4A62C 8006F22C 3C08800B */  lui       $t0, %hi(D_800B0C10)
/* 4A630 8006F230 25080C10 */  addiu     $t0, $t0, %lo(D_800B0C10)
/* 4A634 8006F234 8D090000 */  lw        $t1, ($t0)
/* 4A638 8006F238 8FAA0020 */  lw        $t2, 0x20($sp)
/* 4A63C 8006F23C 00000000 */  nop
/* 4A640 8006F240 AD490000 */  sw        $t1, ($t2)
/* 4A644 8006F244 3C0B800B */  lui       $t3, %hi(D_800B0C10)
/* 4A648 8006F248 256B0C10 */  addiu     $t3, $t3, %lo(D_800B0C10)
/* 4A64C 8006F24C 8D6C0004 */  lw        $t4, 4($t3)
/* 4A650 8006F250 8FAD0024 */  lw        $t5, 0x24($sp)
/* 4A654 8006F254 00000000 */  nop
/* 4A658 8006F258 ADAC0000 */  sw        $t4, ($t5)
/* 4A65C 8006F25C 10000003 */  b         .L8006F26C
/* 4A660 8006F260 00000000 */   nop
/* 4A664 8006F264 10000001 */  b         .L8006F26C
/* 4A668 8006F268 00000000 */   nop
.L8006F26C:
/* 4A66C 8006F26C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4A670 8006F270 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4A674 8006F274 03E00008 */  jr        $ra
/* 4A678 8006F278 00000000 */   nop
