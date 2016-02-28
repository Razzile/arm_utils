#include "ARMDisassembler.h"
#include "Utils.h"

using namespace Utils;

std::string ARMDisassembler::Disassemble(uint32_t addr, uint32_t instr) {
    Opcode opcode = Decode(instr);
    switch (opcode) {
        case Opcode::INVALID: {
            return "invalid";
        } break;
        case Opcode::UNDEFINED: {
            return "undefined";
        } break;

        case Opcode::ADC:
        case Opcode::ADD:
        case Opcode::AND:
        case Opcode::BIC:
        case Opcode::CMN:
        case Opcode::CMP:
        case Opcode::MOV:
        case Opcode::MVN:
        case Opcode::ORR:
        case Opcode::RSB:
        case Opcode::RSC:
        case Opcode::EOR:
        case Opcode::SBC:
        case Opcode::SUB:
        case Opcode::TEQ:
        case Opcode::TST: {
            return DisassembleALU(opcode, instr);
        } break;

        case Opcode::B:
        case Opcode::BL: {
            // return DisassembleBranch(addr, instr, opcode);
        } break;

        case Opcode::BKPT: {
            // return DisassembleBKPT(instr);
        } break;

        case Opcode::BLX: {
            // return DisassembleBLX(instr);
        } break;

        case Opcode::BX: {
            // return DisassembleBX(instr);
        } break;

        case Opcode::CDP: {
            return "cdp";
        } break;

        case Opcode::CLREX: {
            return "clrex";
        } break;

        case Opcode::CLZ: {
            // return DisassembleCLZ(instr);
        } break;

        case Opcode::LDC: {
            return "ldc";
        } break;

        case Opcode::LDM:
        case Opcode::STM: {
            // return DisassembleMemblock(opcode, insn);
        } break;

        case Opcode::LDR:
        case Opcode::LDRB:
        case Opcode::LDRBT:
        case Opcode::LDRT:
        case Opcode::STR:
        case Opcode::STRB:
        case Opcode::STRBT:
        case Opcode::STRT: {
            // return DisassembleMem(insn);
        } break;

        case Opcode::LDREX:
        case Opcode::LDREXB:
        case Opcode::LDREXD:
        case Opcode::LDREXH:
        case Opcode::STREX:
        case Opcode::STREXB:
        case Opcode::STREXD:
        case Opcode::STREXH: {
            // return DisassembleREX(opcode, insn);
        } break;

        case Opcode::LDRH:
        case Opcode::LDRSB:
        case Opcode::LDRSH:
        case Opcode::STRH: {
            // return DisassembleMemHalf(insn);
        } break;

        case Opcode::MCR:
        case Opcode::MRC: {
            // return DisassembleMCR(opcode, insn);
        } break;
        case Opcode::MLA: {
            // return DisassembleMLA(opcode, insn);
        } break;

        case Opcode::MRS: {
            // return DisassembleMRS(insn);
        } break;

        case Opcode::MSR: {
            // return DisassembleMSR(insn);
        } break;

        case Opcode::MUL: {
            // return DisassembleMUL(opcode, insn);
        } break;

        case Opcode::NOP:
        case Opcode::SEV:
        case Opcode::WFE:
        case Opcode::WFI:
        case Opcode::YIELD: {
            // return DisassembleNoOperands(opcode, insn);
        } break;

        case Opcode::PKH: {
            // return DisassemblePKH(insn);
        } break;

        case Opcode::PLD: {
            // return DisassemblePLD(insn);
        } break;

        case Opcode::QADD16:
        case Opcode::QADD8:
        case Opcode::QASX:
        case Opcode::QSAX:
        case Opcode::QSUB16:
        case Opcode::QSUB8:
        case Opcode::SADD16:
        case Opcode::SADD8:
        case Opcode::SASX:
        case Opcode::SHADD16:
        case Opcode::SHADD8:
        case Opcode::SHASX:
        case Opcode::SHSAX:
        case Opcode::SHSUB16:
        case Opcode::SHSUB8:
        case Opcode::SSAX:
        case Opcode::SSUB16:
        case Opcode::SSUB8:
        case Opcode::UADD16:
        case Opcode::UADD8:
        case Opcode::UASX:
        case Opcode::UHADD16:
        case Opcode::UHADD8:
        case Opcode::UHASX:
        case Opcode::UHSAX:
        case Opcode::UHSUB16:
        case Opcode::UHSUB8:
        case Opcode::UQADD16:
        case Opcode::UQADD8:
        case Opcode::UQASX:
        case Opcode::UQSAX:
        case Opcode::UQSUB16:
        case Opcode::UQSUB8:
        case Opcode::USAX:
        case Opcode::USUB16:
        case Opcode::USUB8: {
            // return DisassembleParallelAddSub(opcode, insn);
        } break;

        case Opcode::REV:
        case Opcode::REV16:
        case Opcode::REVSH: {
            // return DisassembleREV(opcode, insn);
        }break;

        case Opcode::SEL: {
            // return DisassembleSEL(insn);
        } break;

        case Opcode::SMLAD:
        case Opcode::SMLALD:
        case Opcode::SMLSD:
        case Opcode::SMLSLD:
        case Opcode::SMMLA:
        case Opcode::SMMLS:
        case Opcode::SMMUL:
        case Opcode::SMUAD:
        case Opcode::SMUSD:
        case Opcode::USAD8:
        case Opcode::USADA8: {
            // return DisassembleMediaMulDiv(opcode, insn);
        } break;

        case Opcode::SSAT:
        case Opcode::SSAT16:
        case Opcode::USAT:
        case Opcode::USAT16: {
            // return DisassembleSAT(opcode, insn);
        } break;

        case Opcode::STC: {
            return "stc";
        } break;

        case Opcode::SWI: {
            // return DisassembleSWI(insn);
        } break;

        case Opcode::SWP:
        case Opcode::SWPB: {
            // return DisassembleSWP(opcode, insn);
        } break;

        case Opcode::SXTAB:
        case Opcode::SXTAB16:
        case Opcode::SXTAH:
        case Opcode::SXTB:
        case Opcode::SXTB16:
        case Opcode::SXTH:
        case Opcode::UXTAB:
        case Opcode::UXTAB16:
        case Opcode::UXTAH:
        case Opcode::UXTB:
        case Opcode::UXTB16:
        case Opcode::UXTH: {
            // return DisassembleXT(opcode, insn);
        } break;

        case Opcode::UMLAL:
        case Opcode::UMULL:
        case Opcode::SMLAL:
        case Opcode::SMULL: {
            // return DisassembleUMLAL(opcode, insn);
        } break;
    }
    return "invalid";
}


std::string ARMDisassembler::DisassembleALU(Opcode opcode, uint32_t instr) {

    uint8_t condition = (instr >> 28) & 0xF;
    uint8_t op = (instr >> 24) & 0xF;
    uint8_t is_immed = (instr >> 25) & 0x1;
    uint8_t bit_s = (instr >> 20) & 0x1;
    uint8_t rn = (instr >> 16) & 0xF;
    uint8_t rd = (instr >> 12) & 0xF;
    uint8_t immed = instr & 0xFF;

    uint8_t flags = 0;

    int opval = (int)opcode;
    const char *opcode_name = opcode_names[opval];

    switch (opcode) {
        // comparison opcodes don't have a destination and dont use 'S' bit
        case Opcode::CMN:
        case Opcode::CMP:
        case Opcode::TEQ:
        case Opcode::TST: {
            flags = kNoDest | kNoSBit;
        } break;

        // mov opcodes don't use operand1
        case Opcode::MOV:
        case Opcode::MVN: {
            flags = kNoOperand1;
        } break;

        default: break;
    }

    // register strings
    std::string rn_str = "";
    std::string rd_str = "";
    // S bit string
    std::string sbit_str = "";

    if ((flags & kNoOperand1) == 0) {
        rn_str = FormatString("r%d", rn);
    }

    if ((flags & kNoDest) == 0) {
        rd_str = FormatString("r%d", rd);
    }

    if (bit_s && !(flags & kNoSBit)) {
        sbit_str = "s";
    }

    if (is_immed) {
        return FormatString("%s%s%s\t%s, %s#%u ; #0x%x",
                            opcode_name,
                            cond_names[condition],
                            sbit_str.data(),
                            rd_str.data(),
                            rn_str.data(),
                            immed,
                            immed);
    }

    uint8_t shift_is_reg = (instr >> 4) & 0x1;
    uint8_t rotation = (instr >> 8) & 0xF;
    uint8_t rm = (instr) & 0xF;
    uint8_t shift_type = (instr >> 5) & 0x3;
    uint8_t rs = (instr >> 8) & 0xF;
    uint8_t shift_amount = (instr >> 7) & 0x1F;
    uint32_t rot_val = immed;
    uint8_t rotate = rot_val << 0x1;

    rot_val = (rot_val >> rotate) | (rot_val << (32 - rotate));

    if (!shift_is_reg && shift_type == 0 && shift_amount ==0) {
        return FormatString("%s%s%s\t%s, %sr%d",
                            opcode_name,
                            cond_names[condition],
                            sbit_str.data(),
                            rd_str.data(),
                            rn_str.data(),
                            rm);
    }

    const char *shift_name = shift_names[shift_type];
    if (shift_is_reg) {
        return FormatString("%s%s%s\t%s, %sr%d, %s r%d",
                            opcode_name,
                            cond_names[condition],
                            sbit_str.data(),
                            rd_str.data(),
                            rn_str.data(),
                            rm,
                            shift_name,
                            rs);
    }

    if (shift_amount == 0) {
        if (shift_type == 3) {
            return FormatString("%s%s%s\t%s, %sr%d, RRX", opcode_name, cond_names[condition], sbit_str.data(), rd_str.data(), rn_str.data(), rm);
        }
        shift_amount = 32;
    }

    return FormatString("%s%s%s\t%s, %sr%d, %s #%u",
                        opcode_name,
                        cond_names[condition],
                        sbit_str.data(),
                        rd_str.data(),
                        rn_str.data(),
                        rm,
                        shift_name,
                        shift_amount);
}

Opcode ARMDisassembler::Decode(uint32_t instr) {
    // first 2 bits of opcode 1
    uint32_t ophi = (instr >> 26) & 0x3;
    switch (ophi) {
        case 0x0: return Decode00(instr);
        case 0x1: return Decode01(instr);
        case 0x2: return Decode10(instr);
        case 0x3: return Decode11(instr);
    }
    return Opcode::INVALID;
}

// Data-processing and misc. instructions (A5.2)
Opcode ARMDisassembler::Decode00(uint32_t instr) {
    uint8_t op = (instr >> 25) & 0x1; // low bit of op 1
    uint8_t op2lo = (instr >> 4) & 0x1; // op (2)

    if (op == 0 && op2lo == 1) {
        if ((instr & 0xFFFFFFF0) == 0x012FFF10) {
            // BX
            return Opcode::BX;
        }

        if ((instr & 0xFF000F0) == 0x1600010) {
            // CLZ
            return Opcode::CLZ;
        }

        if ((instr & 0xFFF000F0) == 0xE1200070) {
            // BKPT
            return Opcode::BKPT;
        }

        // opcode 2
        uint32_t op2 = (instr >> 4) & 0xF;
        if (op2 == 0x9) {
            uint8_t op1hi = (instr >> 24) & 0x1;

            if (op1hi) {
                return DecodeSyncPrimitive(instr);
            }

            return DecodeMUL(instr);
        }

        uint8_t op2hi = (instr >> 7) & 0x1;
        if (op2hi) {
            return DecodeLDRH(instr);
        }
    }

    uint32_t op1_full = (instr >> 20) & 0x1F;
    if (op && (op1_full == 0x12 || op1_full == 0x16)) {
        return DecodeMSRImmAndHints(instr);
    }
    return DecodeALU(instr);
}

// Load/store word and unsigned byte (A5.3)
// TODO: finish these
Opcode ARMDisassembler::Decode01(uint32_t instr) {
    uint8_t A = (instr >> 25) & 0x1; // indicates if target is reg or imm
    uint8_t B = (instr >> 4) & 0x1; // if B=1 and A=1, op is media instruction

    if (A && B) {
        return DecodeMedia(instr);
    }

    uint8_t is_load = (instr >> 20) & 0x1; // target is LDR type
    uint8_t is_byte = (instr >> 22) & 0x1; // target is xxxB type

    if ((instr & 0xFD70F000) == 0xF550F000) {
        return Opcode::PLD;
    }
    // TODO: DMB, DSB and ISB may fit here (see A5.7.1)

    if (instr == 0xF57FF01F) {
        return Opcode::CLREX;
    }

    // LDRx
    if (is_load) {
        if (is_byte) {
            return Opcode::LDRB;
        }
        return Opcode::LDR;
    }
    // STRx
    else {
        if (is_byte) {
            return Opcode::STRB;
        }
        return Opcode::STR;
    }
}

// branch, branch-link and block data transfer (A5.5)
Opcode ARMDisassembler::Decode10(uint32_t instr) {
    // TODO: most instructions here (A5.5)
    uint8_t ophi = (instr >> 25) & 0x1;

    // block data transfer instruction
    if (ophi == 0) {
        uint8_t is_load = (instr >> 20) & 0x1;
        if (is_load) {
            // TODO: LDM, LDMIA, LDMDA, LDMFA, LDMFD, LDMDB, LDMEA, LDMIB, LDMED, POP
            return Opcode::LDC;
        }
        else {
            // TODO: STM, STMDA, STMDB, STMIB, PUSH
            return Opcode::STC;
        }
    }

    // branch type
    uint8_t is_link = (instr >> 24) & 0x1;
    if (is_link) {
        return Opcode::BL;
    }
    return Opcode::B;
}

// Coprocessor instructions and SVC (A5.6)
Opcode ARMDisassembler::Decode11(uint32_t instr) {
    uint8_t op1hi = (instr >> 25) & 0x1;
    if (op1hi == 0) {
        // LDC, STC
        uint8_t is_load = (instr >> 20) & 0x1;

        if (is_load) {
            return Opcode::LDC;
        }
        else {
            return Opcode::STC;
        }
    }

    uint8_t is_swi = (instr >> 24) & 0x1;
    if (is_swi) {
        return Opcode::SWI;
    }

    uint8_t op = (instr >> 4) & 0x1;
    uint8_t coprocessor_num = (instr >> 8) & 0x1;

    // coprocessor 15 is special
    if (coprocessor_num == 15) {
        uint8_t opcode = (instr >> 21) & 0x7;
        if (op == 0 || opcode != 0) {
            // incorrect bit pattern
            return Opcode::UNDEFINED;
        }

        uint8_t is_mrc = (instr >> 20) & 0x1;
        if (is_mrc) {
            return Opcode::MRC;
        }
        else {
            return Opcode::MCR;
        }
    }
    if (op == 0) {
        return Opcode::CDP;
    }

    uint8_t is_mrc = (instr >> 20) & 0x1;
    if (is_mrc) {
        return Opcode::MRC;
    }
    else {
        return Opcode::MCR;
    }
}

Opcode ARMDisassembler::DecodeSyncPrimitive(uint32_t instr) {
    return Opcode::INVALID; // TODO:
}

Opcode ARMDisassembler::DecodeMUL(uint32_t instr) {
    return Opcode::INVALID; // TODO:
}

Opcode ARMDisassembler::DecodeLDRH(uint32_t instr) {
    return Opcode::INVALID; // TODO:
}

Opcode ARMDisassembler::DecodeMSRImmAndHints(uint32_t instr) {
    return Opcode::INVALID; // TODO:
}

Opcode ARMDisassembler::DecodeALU(uint32_t instr) {
    return Opcode::INVALID; // TODO:
}

Opcode ARMDisassembler::DecodeMedia(uint32_t instr) {
    return Opcode::INVALID; // TODO:
}
